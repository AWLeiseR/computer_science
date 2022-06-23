#lang racket
;referente ao nx
(define quantTotalQuad 10)
(define totalFig 50)
(define n 20);quantidade de cada figuras circulos e retangulos (gera um numero aleatorio dentro 0 a 14)
(define nhh (* 4(* quantTotalQuad quantTotalQuad))) ;quantidade do nx de hidrantes
(define nss (* quantTotalQuad quantTotalQuad)) ;quantidade do nx de semaforos
(define nrr (* quantTotalQuad quantTotalQuad)) ;quantidade do nx de torres de radio
(define qQuadras (* quantTotalQuad quantTotalQuad));quantidade de Quadras, essa aqui é a quantidade exata
(define out (open-output-file "/home/lucalliel/Desktop/fileQuadra.geo"));criando txt, cria um txt no diretorio escrito
(define npp (* quantTotalQuad quantTotalQuad))
(define nmm (* quantTotalQuad 1))
(display (string-append "nx" " " (number->string n) " " (number->string qQuadras) " " (number->string nhh) " " (number->string nss) " " (number->string nrr) " " (number->string npp) " " (number->string npp)  "\n") out);coloca o nx no txt
(display (string-append "cq" " " "orange" " " "firebrick" " " (number->string 1.000) "\n") out) ;coloca o cq
(display (string-append "cs" " " "lightred" " " "yellow" " " (number->string 1.000) "\n") out) ;coloca o cs
(display (string-append "ch" " " "red" " " "firebrick" " " (number->string 1.000) "\n") out) ;coloca o ch
(display (string-append "cr" " " "magenta" " " "lightblue" " " (number->string 1.000) "\n") out) ;coloca o cr
(define xFiguras (+ (* quantTotalQuad 60)(* quantTotalQuad 100)))
(define qDir (- quantTotalQuad 1));todas essas variaveis sao referentes as quadras, e como printalas no txt de forma adequada
(define cepIndice qDir)
(define qBaixo 1)
(define ale "q")
(define stringindice 1)
(define xQuadra 20);y da quadra
(define yQuadra 20);x da quadra
(define w 120);w
(define h 90) ;h
(define intervalo 150);é a distancia uma quadra da outra
(define xInicio 20);mudam a cada ciclo
(define yInicio 20)
(define xInicio1 (+ 20 0))
(define yInicio1 (+ 20 0))
(define xHid 20)
(define yHid 20)
(define hcIndice 1)
(define hlIndice 1)
(define quantHid (* 4 (* quantTotalQuad quantTotalQuad)))
(print quantHid)
(define hDir (- quantTotalQuad 1))
(define xInicio2 (+ 20 0))
(define yInicio2 (+ 20 0))
(define xRadio 20)
(define yRadio 20)
(define rcIndice 1)
(define rlIndice 1)
(define rDir (- quantTotalQuad 1))
(define quantRadio (* quantTotalQuad quantTotalQuad))
(define xInicio3 (+ 20 0))
(define yInicio3 (+ 20 0))
(define xSema 20)
(define ySema 20)
(define scIndice 1)
(define slIndice 1)
(define sDir (- quantTotalQuad 1))
(define quantSema (* quantTotalQuad quantTotalQuad))
(define terminonf (+ quantSema(+ quantRadio (+ quantHid qQuadras))))
(print terminonf)
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
  (display (string-append ale " " "b0" (number->string qBaixo) "." (number->string stringindice) " " (number->string xQuadra) " " (number->string yQuadra) " " (number->string w) " " (number->string h)"\n") out)
  (set! stringindice(+ stringindice 1))
  (cond
    [(> stringindice quantTotalQuad) (set! stringindice(+ 1 0))])
  (set! xQuadra(+ xQuadra intervalo))
  (set! qDir(- qDir 1))
    (cond
    [(< hDir 0) (set! yInicio1(+ yInicio1 intervalo))])
  (cond
    [(< hDir 0) (set! xInicio1(+ xInicio1 0))])
  (cond
    [(< hDir 0) (set! xHid(+ xInicio1 0))])
  (cond
    [(< hDir 0) (set! yHid(+ yInicio1 0))])
  (cond
    [(< hDir 0) (set! hlIndice(+ hlIndice 1))])
  (cond
    [(< hDir 0) (set! hDir(+ quantTotalQuad -1))])
  (display (string-append "h" " " "hnb0"(number->string hlIndice)"."(number->string hcIndice)".1" " " (number->string (+ xHid)) " " (number->string (+ yHid 90))"\n") out)
  (display (string-append "h" " " "hnb0"(number->string hlIndice)"."(number->string hcIndice)".2" " " (number->string (+ xHid 65)) " " (number->string (+ yHid 90))"\n") out)
  (display (string-append "h" " " "hnb0"(number->string hlIndice)"."(number->string hcIndice)".3" " " (number->string (+ xHid 120)) " " (number->string (+ yHid 90))"\n") out)
  (display (string-append "h" " " "hnb0"(number->string hlIndice)"."(number->string hcIndice)".4" " " (number->string (+ xHid 120)) " " (number->string (+ yHid 50))"\n") out)
  (set! hcIndice(+ hcIndice 1))
  (cond
    [(> hcIndice quantTotalQuad) (set! hcIndice(+ 1 0))])
  (set! xHid (+ xHid intervalo))
  (set! hDir(- hDir 1))
  (cond
    [(< rDir 0) (set! yInicio2(+ yInicio2 intervalo))])
  (cond
    [(< rDir 0) (set! xInicio2(+ xInicio2 0))])
  (cond
    [(< rDir 0) (set! xRadio(+ xInicio2 0))])
  (cond
    [(< rDir 0) (set! yRadio(+ yInicio2 0))])
  (cond
    [(< rDir 0) (set! rlIndice(+ rlIndice 1))])
  (cond
    [(< rDir 0) (set! rDir(- quantTotalQuad 1))])
  ;(cond
    ;[(not (= rlIndice 2)) (display (string-append "rb" " " idRadio1 (number->string rlIndice) idRadio2 (number->string rcIndice) " " (number->string (+ xRadio 60)) " " (number->string (+ yRadio 45))"\n") out)])
   ;(cond
    ;[(or (not (= rlIndice 1)) (not (= rcIndice 4))) (display (string-append "rb" " " idRadio1 (number->string rlIndice) idRadio2 (number->string rcIndice) " " (number->string (+ xRadio 60)) " " (number->string (+ yRadio 45))"\n") out)])
  (display (string-append "rb" " " "rbb0" (number->string rlIndice) "." (number->string rcIndice) " " (number->string (+ xRadio 60)) " " (number->string (+ yRadio 45))"\n") out)
  (set! rcIndice(+ rcIndice 1))
  (cond
    [(> rcIndice quantTotalQuad) (set! rcIndice(+ 1 0))])
  (set! xRadio(+ xRadio intervalo))
  (set! rDir(- rDir 1))
  (cond
    [(< sDir 0) (set! yInicio3(+ yInicio3 intervalo))])
  (cond
    [(< sDir 0) (set! xInicio3(+ xInicio3 0))])
  (cond
    [(< sDir 0) (set! xSema(+ xInicio3 0))])
  (cond
    [(< sDir 0) (set! ySema(+ yInicio3 0))])
  (cond
    [(< sDir 0) (set! slIndice(+ slIndice 1))])
  (cond
    [(< sDir 0) (set! sDir(- quantTotalQuad 1))])
  ;(cond
    ;[(and (not (= slIndice 3)) (not (= scIndice 2))) (display (string-append "s" " " "sfb0"(number->string scIndice)"."(number->string slIndice) " " (number->string (+ xSema 135)) " " (number->string (+ ySema 10))"\n") out)])
  (display (string-append "s ""sfb0"(number->string slIndice)"."(number->string scIndice) " " (number->string (+ xSema 135)) " " (number->string (+ ySema 10))"\n") out)
  (set! scIndice(+ scIndice 1))
  ;(cond
  ;  [(> slIndice (- quantTotalQuad 1)) (set! slIndice(+ 1 0))])
  (cond
    [(> scIndice quantTotalQuad) (set! scIndice(+ 1 0))])
  (set! xSema (+ xSema intervalo))
  (set! sDir(- sDir 1))
  (set! terminonf(- terminonf 7))
  (cond
    [(> terminonf 0) (funcWhile (+ n -1))]));volta para o inicio da funcao caso ainda existam quadras a serem printadas

(define (random-nslo x);funcao random para circulos retangulos e textos
  (set! x (random 4))
    (cond [(equal? x 0) "n"]
          [(equal? x 1) "s"]
          [(equal? x 2) "l"]
          [(equal? x 3) "o"]
          ))

(define resultado (funcWhile 3)); aki termina de fazer as Quadras
(define quantPredios (* quantTotalQuad quantTotalQuad))
(define pDir (- quantTotalQuad 1));todas essas variaveis sao referentes as quadras, e como printalas no txt de forma adequada
(define prdIndice 1)
(define aleatorioQ1 (random 1 5))
(define aleatorioQ2 (random 1 5))
(define fPredio (random 30 45))
(define pPredio (random 35 70))
(define pMrg (random 10 20))
(define facePredio (random-nslo 0))
(define qPredios 10)
(define (funcWhile4)
  (set! aleatorioQ1 (random 1 5))
  (set! aleatorioQ2 (random 1 5))
  (set! fPredio (random 30 45))
  (set! pPredio (random 35 70))
  (set! pMrg (random 10 20))
  (set! facePredio (random-nslo 0))
  (display (string-append "prd" (number->string prdIndice) " " "b0"(number->string aleatorioQ1)"."(number->string aleatorioQ2) " " facePredio " " (number->string fPredio) " " (number->string pPredio) " " (number->string pMrg) "\n") out)
  (set! qPredios(- qPredios 1))
  (cond
    [(> qPredios 0) (funcWhile4)]))
;referente as figuras
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
(define xFig 30)
(define yFig xFiguras)
(define rFig 0)
(define wFig 0)
(define hFig 0)
(define (funcWhile2)
  (set! aleFig (random-crt 0))
  (set! stringale (random-string 0))
  (set! xFig (random 20 250));numero aleatorio para ponto no eixo x
  (set! yFig (random xFiguras (+ xFiguras 100)));ponto aleatorio para ponto no eixo y
  (set! rFig (random 50));numero aleatorio para o tamanho do raio
  (set! wFig (random 200));largura do retangulo
  (set! hFig (random 200));altura do retangulo
  (cond
    [(string=? "t" aleFig) (set! textCont(+ textCont 1))])
  (cond
    [ (> textCont 3) (set! aleFig (random-cr 0))])
  (cond
    [(string=? aleFig "c") (set! indiceFig(+ indiceFig 1))]
    [(string=? aleFig "r") (set! indiceFig(+ indiceFig 1))])
  (cond
    [(string=? aleFig "c") (set! totalFig(- totalFig 1))]
    [(string=? aleFig "r") (set! totalFig(- totalFig 1))])
  (cond
    [;primeira condição caso for um circulo printa (tipo (id)->ainda nao foi implementado r x y cor1 cor2), os outros seguem respectivamente a mesma ideia
     (string=? "c" aleFig) (display (string-append aleFig " " (number->string indiceFig) " " (number->string rFig) " " (number->string xFig) " " (number->string yFig) " " corFig2 " " corFig1"\n") out)]
    [(string=? "r" aleFig) (display (string-append aleFig " " (number->string indiceFig) " " (number->string wFig) " " (number->string hFig) " " (number->string xFig) " " (number->string yFig) " " corFig1 " " corFig2"\n") out)]
    [(string=? "t" aleFig) (display (string-append aleFig " " (number->string xFig) " " (number->string yFig) " " stringale "\n") out)])
  (cond
    [(> totalFig 0) (funcWhile2 )]))
(define resultado2 (funcWhile2))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;torres de radio mesma logica das quadras, daqui em diante é seguir o que foi visto a cima
(close-output-port out)
  