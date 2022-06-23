#lang racket
;referente ao nx
(define quantTotalQuad 4)
(define n (random 15));quantidade de cada figuras
(define nhh (random 50))
(define nss (random 50))
(define nrr (random 50))
(define qQuadras (* quantTotalQuad quantTotalQuad))
(define out (open-output-file "/home/lucalliel/Desktop/fileQuadra.geo"));criando txt
(display (string-append "nx" " " (number->string n) " " (number->string qQuadras) " " (number->string nss) " " (number->string nrr) " " (number->string nhh)"\n") out)
(display (string-append "cq" " " "orange" " " "firebrick" (number->string 1.000) "\n") out)
(display (string-append "cs" " " "lightred" " " "yellow" (number->string 1.000) "\n") out)
(display (string-append "ch" " " "red" " " "firebrick" (number->string 1.000) "\n") out)
(display (string-append "cr" " " "magenta" " " "lightblue" (number->string 1.000) "\n") out)
;referente as quadras
(define qDir (- quantTotalQuad 1))
(define cepIndice qDir)
(define qBaixo 0)
(define stringcep "CEP-LIN-")
(define stringcep2 "COL-")
(define ale "q")
(define stringindice 0)

(define xQuadra 20)
(define yQuadra 20)
(define w 120)
(define h 90)
(define intervalo 150)

(define xInicio 20);mudam a cada ciclo
(define yInicio 20)

(define (funcWhile n)
  (cond
      [(< qDir 0) (set! yInicio(+  yInicio intervalo))])
  (cond
      [(< qDir 0) (set! xInicio(+  xInicio 0))])
  (cond
      [(< qDir 0) (set! xQuadra(+  xInicio 0))])
  (cond
    [(< qDir 0) (set! yQuadra(+  yInicio 0))])
  (cond
      [(< qDir 0) (set! qBaixo(+ qBaixo 1))])
  (cond
      [(< qDir 0) (set! qDir(+ cepIndice 0))])
  (display (string-append ale " " stringcep (number->string qBaixo) stringcep2 (number->string stringindice) " " (number->string xQuadra) " " (number->string yQuadra) " " (number->string w) " " (number->string h)"\n") out)
  (set! stringindice(+ stringindice 1))
  (cond
    [(> stringindice cepIndice) (set! stringindice(+ 0 0))])
  (set! xQuadra(+ xQuadra intervalo))
  (set! qDir(- qDir 1))
  (set! qQuadras (- qQuadras 1))
  (cond
    [(> qQuadras 0) (funcWhile (+ n -1))]));caso tiver acabado pra baixo

(define resultado (funcWhile 3)); aki termina de fazer as Quadras

;referente as figuras
(define (random-crt x)
  (set! x (random 3))
    (cond [(equal? x 0) "c"]
          [(equal? x 1) "r"]
          [(equal? x 2) "t"]
          ))
(define (random-cr x)
  (set! x (random 2))
    (cond [(equal? x 0) "c"]
          [(equal? x 1) "r"]
          ))
(define (random-string x)
  (set! x (random 3))
    (cond [(equal? x 0) "Primeira String Teste"]
          [(equal? x 1) "Teste Segunda String"]
          [(equal? x 2) "String Teste Terceira"]
          ))
(define stringale random-string)
(define aleFig (random-crt 0))
(define corFig1 "Blue")
(define corFig2 "Yellow")
(define indiceFig 0)
(define textCont 0)
(define xFig 0)
(define yFig 0)
(define rFig 0)
(define wFig 0)
(define hFig 0)
(define (funcWhile2 n)
  (set! aleFig (random-crt 0))
  (cond
    [(string=? ale "c") (set! indiceFig(+ indiceFig 1))]
    [(string=? ale "r") (set! indiceFig(+ indiceFig 1))])
  (set! stringale (random-string 0))
  (set! xFig (random 0 5));numero aleatorio para ponto no eixo x
  (set! yFig (random 150  300));ponto aleatorio para ponto no eixo y
  (set! rFig (random 50));numero aleatorio para o tamanho do raio
  (set! wFig (random 200));largura do retangulo
  (set! hFig (random 200));altura do retangulo
  (cond
    [(string=? "t" aleFig) (set! textCont(+ textCont 1))])
  (cond
    [ (> textCont 3) (set! aleFig (random-cr 0))])
  (cond
    [;primeira condição caso for um circulo printa (tipo (id)->ainda nao foi implementado r x y cor1 cor2), os outros seguem respectivamente a mesma ideia
     (string=? "c" aleFig) (display (string-append aleFig " " (number->string indiceFig) " " (number->string rFig) " " (number->string xFig) " " (number->string yFig) " " corFig1 " " corFig2"\n") out)]
    [(string=? "r" ale) (display (string-append aleFig " " (number->string indiceFig) " " (number->string wFig) " " (number->string hFig) " " (number->string xFig) " " (number->string yFig) " " corFig1 " " corFig2"\n") out)]
    [(string=? "t" ale) (display (string-append aleFig " " (number->string xFig) " " (number->string yFig) " " stringale "\n") out)])
  (cond
    [(> n 0) (funcWhile2 (- n 1))]
    [else (print "acabou a func")]))
(define resultado2 (funcWhile2 5))
;falta fazer semaforos, torres de radio e hidrantes
(set! xInicio (+ 20 0))
(set! yInicio (+ 20 0))
(define xRadio 20)
(define yRadio 20)
(define rcIndice 0)
(define rlIndice 0)
(define idRadio1 "rbb.")
(define idRadio2 ".")
(define rDir (- quantTotalQuad 1))
(define quantRadio (* quantTotalQuad quantTotalQuad))
(print quantRadio)
(define (funcWhile3)
  (cond
    [(< rDir 0) (set! yInicio(+ yInicio intervalo))])
  (cond
    [(< rDir 0) (set! xInicio(+ xInicio 0))])
  (cond
    [(< rDir 0) (set! xRadio(+ xInicio 0))])
  (cond
    [(< rDir 0) (set! yRadio(+ yInicio 0))])
  (cond
    [(< rDir 0) (set! rlIndice(+ rlIndice 1))])
  (cond
    [(< rDir 0) (set! rDir(- quantTotalQuad 1))])
  (cond
    [(not (= rlIndice 2)) (display (string-append "rb" " " idRadio1 (number->string rlIndice) idRadio2 (number->string rcIndice) " " (number->string (+ xRadio 60)) " " (number->string (+ yRadio 45))"\n") out)])
  (set! rlIndice(+ rlIndice 1))
  (cond
    [(> rlIndice (- quantTotalQuad 1)) (set! rlIndice(+ 0 0))])
  (set! xRadio(+ xRadio intervalo))
  (set! rDir(- rDir 1))
  (set! quantRadio(- quantRadio 1))
  (cond
    [(> quantRadio 0) (funcWhile3)]))
(define resultado3 (funcWhile3))
(set! xInicio (+ 20 0))
(set! yInicio (+ 20 0))
(define xSema 20)
(define ySema 20)
(define scIndice 0)
(define slIndice 0)
(define idSema1 "sff.")
(define idSema2 ".")
(close-output-port out)
  