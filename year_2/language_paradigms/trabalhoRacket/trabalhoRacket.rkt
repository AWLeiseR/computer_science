#lang racket
(define val1 "nx")
(define n (random 5000))
(define (random-crt x)
  (set! x (random 3))
    (cond [(equal? x 0) "c"]
          [(equal? x 1) "r"]
          [(equal? x 2) "t"]
          ))
(define (random-string x)
  (set! x (random 3))
    (cond [(equal? x 0) "Primeira String Teste"]
          [(equal? x 1) "Teste Segunda String"]
          [(equal? x 2) "String Teste Terceira"]
          ))
(define stringale random-string)
(define indice 0)
(define out (open-output-file "C:\Users\Alan\Desktop\test.txt"));criando txt
(display (string-append val1 " " (number->string n)"\n") out);inserindo nx
(define ale random-crt) ;;gerando uma das 3 letras aleatorias (c,t,r)
(define cor1 "Blue");cor fixa1
(define cor2 "Yellow");cor fixa2
(define x (random 150));numero aleatorio para ponto no eixo x
(define y (random 150));ponto aleatorio para ponto no eixo y
(define r (random 50));numero aleatorio para o tamanho do raio
(define w (random 200));largura do retangulo
(define h (random 200));altura do retangulo
(define stringfixa "String para o testar o Texto")
(define (funcWhile n)
  (set! indice (+ indice 1))
  (set! ale (random-crt 0))
  (set! stringale (random-string 0))
  (set! x (random 150));numero aleatorio para ponto no eixo x
  (set! y (random 150));ponto aleatorio para ponto no eixo y
  (set! r (random 50));numero aleatorio para o tamanho do raio
  (set! w (random 200));largura do retangulo
  (set! h (random 200));altura do retangulo
  (cond
    [;primeira condição caso for um circulo printa (tipo (id)->ainda nao foi implementado r x y cor1 cor2), os outros seguem respectivamente a mesma ideia
     (string=? "c" ale) (display (string-append ale " " (number->string indice) " " (number->string r) " " (number->string x) " " (number->string y) " " cor1 " " cor2"\n") out)]
    [(string=? "r" ale) (display (string-append ale " " (number->string indice) " " (number->string w) " " (number->string h) " " (number->string x) " " (number->string y) " " cor1 " " cor2"\n") out)]
    [(string=? "t" ale) (display (string-append ale " " (number->string indice) " " (number->string x) " " (number->string y) " " stringale "\n") out)])
  (cond
    [(> n 0) (funcWhile (- n 1))]
    [else (print "acabou a func")]))
(define resultado (funcWhile 100))
(close-output-port out)