#lang racket
;Qry T3
;▪brl(x,y) coordenada q detonará a bomba 
;▪fi(x,y,ns,r) coordenada iniciada em x,y. Encontrar os ns semáforos mais próximos, e os hidratantes q estejam a dentro do raio e
;▪Fh([+|-]k,cep,face,num) determina os k hidrantes mais proximos (-k) ou os mais distantes (+k) do endereço
;▪fs(k,cep,face,num) determina os k semáforos mais próximos do endereço
(display "Nome do arquivo: ")
(define a (read-line (current-input-port) 'any))
(printf "Nome do arquivo: ~a\n" a)
(define in (open-input-file a));abre o arquivo
(define nx(values (read-line in)));le a primeira linha
;funcao q tira o nx
(define (con w)
  (substring w 3))
;chama a funcao
(define r(con nx))
;divide a string em varias partes
(define b(string-split r))
;funcao que transforma string em numero
(define (num a)
  (string->number a))
;aplica a funcao num em todos os elementos da lista de strings(b)
(define valorNX (map num b))
(printf"valores ~a"valorNX)