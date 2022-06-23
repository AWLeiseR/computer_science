#lang racket
(provide (all-defined-out))

;Imprime Definicoes iniciais nx,cores...
(define (funComeco n qQuadras nhh nss nrr npp nmm out cor1 cor2)
 ;coloca o nx no txt 
(display (string-append "nx" " " (number->string n) " " (number->string qQuadras) " " (number->string nhh) " "
(number->string nss) " " (number->string nrr) " " (number->string npp) " " (number->string npp)  "\n") out)
 ;coloca o cq
(display (string-append "cq" " " cor1 " " "firebrick" " " (number->string 1.000) "\n") out)
  ;coloca o cs
(display (string-append "cs" " " "black" " " "yellow" " " (number->string 1.000) "\n") out)
  ;coloca o ch
(display (string-append "ch" " " "red" " " "firebrick" " " (number->string 1.000) "\n") out)
  ;coloca o cr
(display (string-append "cr" " " cor2 " " "black" " " (number->string 1.000) "\n") out)) 

;quadras
(define (quadra ale qB stringindice xQ yQ w h out)
  (display (string-append ale " " "b0" (number->string qB) "."
                          (number->string stringindice) " " (number->string xQ) " " (number->string yQ) " "
                          (number->string w) " " (number->string h)"\n") out)
  
  (display (string-append "mur" " " (number->string xQ) " " (number->string (+ 10(+ yQ h))) " "
                          (number->string (+ xQ 35)) " " (number->string (+ 15(+ yQ h))) "\n") out))

;hidrante
(define (hidrante hlIndice  hcIndice xH yH out)
  (display (string-append "h" " " "hnb0"(number->string hlIndice)"."(number->string hcIndice)".1" " "
                          (number->string (+ xH)) " " (number->string (+ yH 90))"\n") out)
  
  (display (string-append "h" " " "hnb0"(number->string hlIndice)"."(number->string hcIndice)".2" " "
                          (number->string (+ xH 65)) " " (number->string (+ yH 90))"\n") out)
  
  (display (string-append "h" " " "hnb0"(number->string hlIndice)"."(number->string hcIndice)".3" " "
                          (number->string (+ xH 120)) " " (number->string (+ yH 90))"\n") out)
  
  (display (string-append "h" " " "hnb0"(number->string hlIndice)"."(number->string hcIndice)".4" " "
                          (number->string (+ xH 120)) " " (number->string (+ yH 50))"\n") out))


(define (Cond1 qDir yInicio intervalo);1
  (if (< qDir 0)
       (+  yInicio intervalo)
         yInicio))

(define (Cond2 qDir xInicio xQuadra);2
  (if (< qDir 0)
      xInicio
      xQuadra))

(define (Cond3 qDir  yInicio yQuadra);3
  (if (< qDir 0)
      yInicio
      yQuadra))

(define (Cond4  qDir  qBaixo);4
  (if (< qDir 0)
      (+ qBaixo 1)
      qBaixo))

(define (Cond5 qDir quantTotalQuad);5
  (if (< qDir 0)
      (- quantTotalQuad 1)
      qDir))