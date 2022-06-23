/*toal de linhas*/
select count(*) from revista.users;
select count(*) from revista.postagem;
select count(*) from revista.views;

/*====== postagens por dia da semana*/

select (case when table1.num is not null 
		then table1.num else 0 end), table2.dia from
(SELECT count(*) as num,
  to_char(createat, 'Day') AS dia from revista.postagem group by dia, createat ) as table1 
  full join (select to_char((date_trunc('week',current_date)::date) + i,'Day') as dia from generate_series(0,6) i) as table2
  on table1.dia = table2.dia

/*====== postagens relacionadas*/

select table2.idpostagem,postagem.titulo, postagem.subtitulo from (select visualizacoes.idpostagem from revista.visualizacoes
join (select iduser, idpostagem from revista.visualizacoes 
where idpostagem = 4 group by iduser, visualizacoes.idpostagem) as table1
on visualizacoes.iduser = table1.iduser and visualizacoes.idpostagem != 4
group by visualizacoes.idpostagem ) as table2 join revista.postagemareas on table2.idpostagem = postagemareas.idpostagem 
join revista.postagem on table2.idpostagem = postagem.postagemid LIMIT  3 


/*===============media mes*/
/*mediaViewsMonth()*/
select avg(table3.qtd) as media
from (select (case when table2.num is not null 
then table2.num else 0 end) as qtd from (select (date_trunc('day',(current_date-30)::date)::date)+(i*1) as dia 
from generate_Series(0,30) i) as table1 join 
(select count(*) as num , visualizacaodata as dia from revista.visualizacoes group by visualizacaodata) as table2 
on table1.dia = table2.dia and table1.dia < current_date+1 and table1.dia > current_date -31) as table3

/*===========visualizacoes do dia atual*/
create or replace function revista.todayViews()
	returns bigint as $$
		select count(*) as total from revista.visualizacoes where visualizacoes.visualizacaodata = current_date;
$$ LANGUAGE SQL;

/*===========porcentagem de crescimento*/
select (revista.todayViews()*100)/revista.mediaViewsMonth() as balanco;

/*===========Score dos usuarios*/
/*ordenar de forma decrescente*/
create or replace function revista.userScore()
	returns table (score bigint, iduser int) as $$
	select ((case when table1.scoreView is not NULL then table1.scoreView *5 else 0 end) +
			(case when table3.scoreHigh is not NULL then table3.scoreHigh *5 else 0 end) + 
			(case when table2.scorePost is not NULL then table2.scorePost *10 else 0 end)) as score, 
			table1.iduser from 
	(select userid as iduser from revista.users)as table_user 
	full join (select count(*) as scorePost, autor from revista.postagem group by autor) as table2 on table2.autor = table_user.iduser
	full join (select count(*) as scoreHigh, iduser from revista.highlights group by iduser) as table3 on table3.iduser = table_user.iduser 
	full join (select count(*) as scoreView, iduser from revista.visualizacoes where iduser > 0 group by iduser) as table1 
	on table1.iduser = table_user.iduser 
	limit 5;
$$ LANGUAGE SQL;