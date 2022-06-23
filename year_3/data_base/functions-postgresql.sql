--------------------------
-- FUNÇÕES SQL SIMPLES ---
--------------------------

CREATE TABLE company.employee2 AS SELECT * FROM company.employee;

--Função sem retorno que remove os empregados com salário menor que uma constante
CREATE OR REPLACE FUNCTION company.remove_pobre() RETURNS void AS $$
    DELETE FROM company.employee2 WHERE salary < 26000;
  $$ LANGUAGE SQL;

BEGIN;
SELECT company.remove_pobre();
ROLLBACK;

--Função sem retorno que remove os empregados com salário menor que o parâmetro fornecido
CREATE OR REPLACE FUNCTION company.remove_pobre(salario NUMERIC) RETURNS void AS $$
    DELETE FROM company.employee2 WHERE salary < salario;
  $$ LANGUAGE SQL;

BEGIN;
SELECT company.remove_pobre(40000);
ROLLBACK;

--Função que retorna uma tupla (empregado com menor salário)
CREATE OR REPLACE FUNCTION company.list_pobre() RETURNS RECORD AS $$
    SELECT * FROM company.employee2 WHERE salary <= ALL (SELECT salary FROM company.employee) LIMIT 1;
    -- Alternativa
    -- SELECT * FROM company.employee2 WHERE salary = ALL (SELECT MIN(salary) FROM company.employee) LIMIT 1;
  $$ LANGUAGE SQL;

SELECT company.list_pobre();

--Função que retorna uma relação (empregados com salário menor que o empregado passado como parâmetro)
CREATE OR REPLACE FUNCTION company.list_pobre(my_ssn INTEGER)
  RETURNS TABLE(ssn INT, salary NUMERIC, fname VARCHAR, lname VARCHAR) AS $$
    SELECT ssn, salary, fname, lname FROM company.employee2 WHERE salary < ALL (SELECT salary FROM company.employee WHERE ssn=my_ssn);
  $$ LANGUAGE SQL;

SELECT * FROM company.list_pobre(123456789);
SELECT * FROM company.list_pobre(123456789) p JOIN company.department d ON p.dno=d.dnumber;

--Função que retorna um valor único
CREATE OR REPLACE FUNCTION company.my_random_int(max_value INTEGER) RETURNS INTEGER AS $$
  SELECT (random() * max_value)::INTEGER;
$$ LANGUAGE SQL;

SELECT company.my_random_int(100000);

------------------
-- FUNÇÕES EM C --
------------------
--Criar o arquivo com o código fonte: /home/dskaster/potencia.cpp
#include "postgres.h"
#include "fmgr.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

/* OLD STYLE
int power(int x, int y) {
  int i;
  int ret = 1;
  for (i=0; i<y; i++)
    ret = ret * x;
  return ret;
}
*/

PG_FUNCTION_INFO_V1(power1);

Datum
power1(PG_FUNCTION_ARGS)
{
  int32 x = PG_GETARG_INT32(0);
  int32 y = PG_GETARG_INT32(1);
  int32 i;
  int32 ret = 1;
  for (i=0; i<y; i++)
    ret = ret * x;
  PG_RETURN_INT32(ret);
}
  
--compilar a biblioteca
dskaster@ubuntu:~$ gcc -I/usr/include/postgresql/9.3/server -fpic -shared -o potencia.so potencia.cpp

--Run as user dskaster in database dskaster
CREATE OR REPLACE FUNCTION power(INTEGER, INTEGER)
RETURNS INTEGER AS
'/home/dskaster/potencia.so', 'power1'
LANGUAGE C STRICT;

--Use the C function via SQL
SELECT power(2,3);


-------------------------------------
-- FUNÇÕES E PROCEDURES EM PLPGSQL --
-------------------------------------

-- Suponha que deseja-se reforçar as senhas de usuários com algumas restrições:
-- a) não pode ser vazia ou idêntica ao login (reverso)
-- b) tem que conter letras e números
-- c) não pode coincidir com um dicionário de senhas proibidas

-- Instruções para popular a relação user ou resetar os valores
INSERT INTO j2ee.user(id, login, nome, senha, nascimento) VALUES (49, 'daniel', 'daniel', '', '1980-10-10');
INSERT INTO j2ee.user(id, login, nome, senha, nascimento) VALUES (50, 'joao', 'Joao', md5(''), '1980-10-10');
INSERT INTO j2ee.user(id, login, nome, senha, nascimento) VALUES (51, 'marcia', 'Marcia', md5('Mar12'), '1980-10-10');
INSERT INTO j2ee.user(id, login, nome, senha, nascimento) VALUES (52, 'ana', 'Ana', md5('senha1234'), '1980-10-10');
UPDATE j2ee.user SET senha=md5('daniel') WHERE id=49;
UPDATE j2ee.user SET senha=md5('') WHERE id=50;
UPDATE j2ee.user SET senha=md5('Mar12') WHERE id=51;
UPDATE j2ee.user SET senha=md5('senha1234') WHERE id=52;
SELECT * FROM j2ee.user;

-- Criar um dicionário de senhas proibidas
CREATE TABLE j2ee.forbidden_words(
  plain_word VARCHAR,
  md5_word VARCHAR,
  CONSTRAINT pk_forbidden_words PRIMARY KEY(plain_word)
);

-- Abaixo uso uma extensão do PostgreSQL que permite inserir múltiplas tuplas em uma única instrução INSERT
INSERT INTO j2ee.forbidden_words(plain_word, md5_word)
  VALUES ('senha1234', md5('senha1234')), ('s1', md5('s1'));
SELECT * FROM j2ee.forbidden_words;

-- Criar uma função que faça verificações na senha e, caso seja aceita, retorna o seu hash MD5
CREATE OR REPLACE FUNCTION j2ee.passwd(_login VARCHAR, _senha VARCHAR)
  RETURNS VARCHAR AS $$
DECLARE
  c RECORD;
BEGIN
  IF trim(_senha) = '' THEN
    RAISE EXCEPTION 'Senha vazia. user=%, passwd=%', _login, _senha;
  END IF;
  IF trim(_senha) = _login OR trim(_senha) = reverse(_login) THEN
    RAISE EXCEPTION 'Senha coincide com login (reverso). user=%, passwd=%', _login, _senha;
  END IF;
  PERFORM regexp_matches(_senha, '[0-9]+');
  IF NOT FOUND THEN
    RAISE EXCEPTION 'Senha deve ter dígito. user=%, passwd=%', _login, _senha;  
  END IF;
  PERFORM regexp_matches(_senha, '[a-z]+');
  IF NOT FOUND THEN
    RAISE EXCEPTION 'Senha deve ter caracter. user=%, passwd=%', _login, _senha;  
  END IF;
  -- A verificação abaixo não precisa usar um cursor, mas fiz assim apenas para exemplificar
  -- A função check_passwd abaixo usa um teste bem mais eficiente
  FOR c IN (SELECT plain_word FROM j2ee.forbidden_words) LOOP
    IF trim(_senha) = c.plain_word THEN
	  RAISE EXCEPTION 'Senha coincide com palavra em dicionário. user=%, passwd=%', _login, _senha;
    END IF;
  END LOOP;
  RETURN md5(_senha);
END;
$$ LANGUAGE PLPGSQL;

SELECT j2ee.passwd('teste', 'teste');
SELECT j2ee.passwd('teste', 'senha1234');
SELECT j2ee.passwd('teste', 'Tjfa90');

-- Agora suponha que já existem usuários armazenados, que não se sabe se a senha satisfaz os novos critérios
-- Deseja-se detectar senhas que não satisfazem e fazer a troca por uma nova senha aleatória

-- Como as senhas estão armazenadas em MD5, a verificação de conter número e letra é inviável
-- Assim, serão verificadas as senhas vazias, que coincidem com o login ou com o dicionário
CREATE OR REPLACE FUNCTION j2ee.check_passwd(_login VARCHAR, _senha VARCHAR) RETURNS BOOLEAN AS $$
DECLARE
  _plword VARCHAR;
BEGIN
  IF _senha = md5('') THEN
    RAISE NOTICE 'Senha vazia. user=%', _login;
    RETURN false;
  ELSEIF _senha = md5(_login) OR _senha = md5(reverse(_login)) THEN
    RAISE NOTICE 'Senha coincide com login (reverso). user=%', _login;
    RETURN false;
  END IF;
  SELECT plain_word INTO _plword FROM j2ee.forbidden_words WHERE md5_word = _senha;
  IF FOUND THEN
    RAISE NOTICE 'Senha coincide com dicionário. user=%, passwd=%', _login, _plword;
    RETURN false;
  END IF;
  RETURN true;  
END;
$$ LANGUAGE PLPGSQL;

SELECT login, j2ee.check_passwd(login, senha) FROM j2ee.user;

-- Implementação de um gerador de senhas

-- Lógica básica
SELECT substr(md5(random()::TEXT), 1, 8);

-- Função que gera uma senha, em texto plano, válida
CREATE OR REPLACE FUNCTION j2ee.gen_passwd() RETURNS VARCHAR AS $$
DECLARE
  plain_passwd VARCHAR;
BEGIN
  LOOP
    SELECT substr(md5(random()::TEXT), 1, 8) INTO plain_passwd;
    PERFORM regexp_matches(plain_passwd, '[0-9]+');
    IF FOUND THEN
      PERFORM regexp_matches(plain_passwd, '[a-z]+');
      EXIT WHEN FOUND;
    END IF;
  END LOOP;
  RETURN plain_passwd;
END;
$$ LANGUAGE PLPGSQL;

SELECT login, j2ee.gen_passwd() FROM j2ee.user;

-- Tabela para armazenar as senhas geradas, para informar aos respectivos usuários
CREATE TABLE j2ee.changed_passwd(
  login VARCHAR(50),
  senha VARCHAR(10),
  change_time TIMESTAMP
);

-- Tentativas de troca de senha
-- a) (ERRO) O UPDATE a seguir atribui a mesma senha para todos os usuários, então não funciona
BEGIN;
UPDATE j2ee.user SET senha=md5('hh1281ao')
  WHERE NOT j2ee.check_passwd(login, senha);
SELECT login, senha FROM j2ee.user;
ROLLBACK;

-- b) (ERRO) Não há INSERT from UPDATE em SQL. Além disso, o UPDATE a seguir atribui senhas diferentes para os usuários, mas na cláusula RETURNING devolve uma senha diferente da senha gerada na cláusula SET, então a lógica também não funciona.
BEGIN;
INSERT INTO j2ee.changed_passwd
  UPDATE j2ee.user SET senha=j2ee.passwd(login, j2ee.gen_passwd())
  WHERE NOT j2ee.check_passwd(login, senha)
  RETURNING login, j2ee.gen_passwd(), now();
ROLLBACK;

-- Ilustrando o problema da lógica (senhas retornadas pelo UPDATE e pelo SELECT abaixo são diferentes, porque o gen_passwd gera uma senha diferente a cada chamada)
BEGIN;
UPDATE j2ee.user SET senha=j2ee.passwd(login, j2ee.gen_passwd())
  WHERE NOT j2ee.check_passwd(login, senha)
  RETURNING login, j2ee.passwd(login, j2ee.gen_passwd()), now();
SELECT login, senha FROM j2ee.user;
ROLLBACK;

-- c) (OK) O procedimento a seguir funciona, usando um cursor implícito
CREATE OR REPLACE FUNCTION j2ee.update_passwords() RETURNS void AS $$
DECLARE
  curr_user RECORD;
  plain_passwd VARCHAR;
BEGIN
  FOR curr_user IN (SELECT login, senha FROM j2ee.user
                    WHERE NOT j2ee.check_passwd(login, senha)) LOOP
    SELECT j2ee.gen_passwd(curr_user.login) INTO plain_passwd;
    UPDATE j2ee.user SET senha=j2ee.passwd(curr_user.login, plain_passwd)
      WHERE login=curr_user.login;
    INSERT INTO j2ee.changed_passwd(login, senha, change_time)
      VALUES(curr_user.login, plain_passwd, now());
    RAISE NOTICE 'Generated password for user %', curr_user.login;
  END LOOP;
END;
$$ LANGUAGE PLPGSQL;

SELECT j2ee.update_passwords();

SELECT DISTINCT ON(login) * FROM j2ee.changed_passwd
  ORDER BY login, change_time DESC;

-- d) (OK) Complementando, a lógica abaixo de um INSERT seguido de UPDATE também funciona para esse caso específico. Mas, a solução baseada em stored procedure é muito mais flexível e se aplica a vários outros casos para os quais uma solução como a abaixo não funcionaria.
BEGIN;
INSERT INTO j2ee.changed_passwd
  SELECT login, j2ee.gen_passwd(), now()
  FROM j2ee.user WHERE NOT j2ee.check_passwd(login, senha);
UPDATE j2ee.user u SET
  senha=j2ee.passwd(
    u.login,
    (SELECT c.senha FROM j2ee.changed_passwd c
     WHERE c.login=u.login
     ORDER BY change_time DESC LIMIT 1)
  )
  WHERE NOT j2ee.check_passwd(u.login, u.senha);
SELECT login, senha FROM j2ee.user;
ROLLBACK;































