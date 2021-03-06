#lang racket
;referente ao nx
(define quantTotalQuad 4)
(define n (random 15));quantidade de cada figuras circulos e retangulos (gera um numero aleatorio dentro 0 a 14)
(define nhh 100) ;quantidade do nx de hidrantes
(define nss 100) ;quantidade do nx de semaforos
(define nrr 100) ;quantidade do nx de torres de radio
(define qQuadras (* quantTotalQuad quantTotalQuad)) ;quantidade de Quadras, essa aqui é a quantidade exata
(define out (open-output-file "/home/lucalliel/Desktop/fileQuadra.geo"));criando txt, cria um txt no diretorio escrito
(display (string-append "nx" " " (number->string n) " " (number->string qQuadras) " " (number->string nss) " " (number->string nrr) " " (number->string nhh)"\n") out);coloca o nx no txt
(display (string-append "cq" " " "orange" " " "firebrick" " " (number->string 1.000) "\n") out) ;coloca o cq
(display (string-append "cs" " " "lightred" " " "yellow" " " (number->string 1.000) "\n") out) ;coloca o cs
(display (string-append "ch" " " "red" " " "firebrick" " " (number->string 1.000) "\n") out) ;coloca o ch
(display (string-append "cr" " " "magenta" " " "lightblue" " " (number->string 1.000) "\n") out) ;coloca o cr
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define qDir (- quantTotalQuad 1));todas essas variaveis sao referentes as quadras, e como printalas no txt de forma adequada
(define cepIndice qDir)
(define qBaixo 1)
(define stringcep "b0")
(define stringcep2 ".")
(define ale "q")
(define stringindice 1)

(define xQuadra 20);y da quadra
(define yQuadra 20);x da quadra
(define w 120);w
(define h 90) ;h
(define intervalo 150) ; é a distancia uma quadra da outra

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
    [(> stringindice 4) (set! stringindice(+ 1 0))])
  (set! xQuadra(+ xQuadra intervalo))
  (set! qDir(- qDir 1))
  (set! qQuadras (- qQuadras 1))
  (cond
    [(> qQuadras 0) (funcWhile (+ n -1))]));volta para o inicio da funcao caso ainda existam quadras a serem printadas

(define resultado (funcWhile 3)); aki termina de fazer as Quadras

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;referente as figuras
(define (random-crt x);funcao random para circulos retangulos e textos
  (set! x (random 3))
    (cond [(equal? x 0) "c"]
          [(equal? x 1) "r"]
          [(equal? x 2) "t"]
          ))
(define (random-cr x);funcao referente para circulos e retangulos
  (set! x (random 2))
    (cond [(equal? x 0) "c"]
          [(equal? x 1) "r"]
          ))
(define (random-string x);funcao que escolhe dentre 3 strings 
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
    [(> n 0) (funcWhile2 (- n 1))]))
(define resultado2 (funcWhile2 5))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;torres de radio mesma logica das quadras, daqui em diante é seguir o que foi visto a cima
(set! xInicio (+ 20 0))
(set! yInicio (+ 20 0))
(define xRadio 20)
(define yRadio 20)
(define rcIndice 1)
(define rlIndice 1)
(define idRadio1 "rbb0")
(define idRadio2 ".")
(define rDir (- quantTotalQuad 1))
(define quantRadio (* quantTotalQuad quantTotalQuad))
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
  ;(cond
    ;[(not (= rlIndice 2)) (display (string-append "rb" " " idRadio1 (number->string rlIndice) idRadio2 (number->string rcIndice) " " (number->string (+ xRadio 60)) " " (number->string (+ yRadio 45))"\n") out)])
   (cond
    [(or (not (= rlIndice 1)) (not (= rcIndice 4))) (display (string-append "rb" " " idRadio1 (number->string rlIndice) idRadio2 (number->string rcIndice) " " (number->string (+ xRadio 60)) " " (number->string (+ yRadio 45))"\n") out)])
  (set! rcIndice(+ rcIndice 1))
  (cond
    [(> rcIndice 4) (set! rcIndice(+ 1 0))])
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
(define scIndice 1)
(define slIndice 1)
(define idSema1 "sfb0");sfb0Coluna.Linha
(define idSema2 ".")
(define sDir (- quantTotalQuad 1))
(define quantSema (* quantTotalQuad quantTotalQuad))
(define (funcWhile4)
  (cond
    [(< sDir 0) (set! yInicio(+ yInicio intervalo))])
  (cond
    [(< sDir 0) (set! xInicio(+ xInicio 0))])
  (cond
    [(< sDir 0) (set! xSema(+ xInicio 0))])
  (cond
    [(< sDir 0) (set! ySema(+ yInicio 0))])
  (cond
    [(< sDir 0) (set! slIndice(+ slIndice 1))])
  (cond
    [(< sDir 0) (set! sDir(- quantTotalQuad 1))])
  (cond
    [(and (not (= slIndice 3)) (not (= scIndice 2))) (display (string-append "sfb0"(number->string scIndice)"."(number->string slIndice) " " (number->string (+ xSema 135)) " " (number->string (+ ySema 10))"\n") out)])
  ;(display (string-append "sfb0"(number->string scIndice)"."(number->string slIndice) " " (number->string (+ xSema 135)) " " (number->string (+ ySema 10))"\n") out)
  (set! scIndice(+ scIndice 1))
  ;(cond
  ;  [(> slIndice (- quantTotalQuad 1)) (set! slIndice(+ 1 0))])
  (cond
    [(> scIndice 4) (set! scIndice(+ 1 0))])
  (set! xSema (+ xSema intervalo))
  (set! sDir(- sDir 1))
  (set! quantSema(- quantSema 1))
  (cond
    [(> quantSema 0) (funcWhile4)]))
(define resultado4 (funcWhile4))
(set! xInicio (+ 20 0))
(set! yInicio (+ 20 0))
(define xHid 20)
(define yHid 20)
(define hcIndice 1)
(define hlIndice 1)
(define idHid1 "sfb0")
(define idHid2 ".")
(define quantHid (* quantTotalQuad quantTotalQuad))
(define hDir (+ 3 0))
(define (funcWhile5)
  (cond
    [(< hDir 0) (set! yInicio(+ yInicio intervalo))])
  (cond
    [(< hDir 0) (set! xInicio(+ xInicio 0))])
  (cond
    [(< hDir 0) (set! xHid(+ xInicio 0))])
  (cond
    [(< hDir 0) (set! yHid(+ yInicio 0))])
  (cond
    [(< hDir 0) (set! hlIndice(+ hlIndice 1))])
  (cond
    [(< hDir 0) (set! hDir(+ 3 0))])
  (display (string-append "hneb0"(number->string hlIndice)"."(number->string hcIndice) " " (number->string (+ xHid)) " " (number->string (+ yHid 90))"\n") out)
  (display (string-append "hnb0"(number->string hlIndice)"."(number->string hcIndice) " " (number->string (+ xHid 65)) " " (number->string (+ yHid 90))"\n") out)
  (display (string-append "hnob0"(number->string hlIndice)"."(number->string hcIndice) " " (number->string (+ xHid 120)) " " (number->string (+ yHid 90))"\n") out)
  (display (string-append "hob0"(number->string hlIndice)"."(number->string hcIndice) " " (number->string (+ xHid 120)) " " (number->string (+ yHid 50))"\n") out)
  (set! hcIndice(+ hcIndice 1))
  (cond
    [(> hcIndice 4) (set! hcIndice(+ 1 0))])
  (set! xHid (+ xHid intervalo))
  (set! hDir(- hDir 1))
  (set! quantHid(- quantHid 1))
  (cond
    [(> quantHid 0) (funcWhile5)]))
(define resultado5 (funcWhile5))
(close-output-port out)
  