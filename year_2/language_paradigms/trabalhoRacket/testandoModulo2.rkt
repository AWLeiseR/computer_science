#lang racket
(provide (all-defined-out))

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
;quadras
(define (quadra ale qB stringindice xQ yQ w h out)
  (display (string-append ale " " "b0" (number->string qB) "."
                          (number->string stringindice) " " (number->string xQ) " " (number->string yQ) " "
                          (number->string w) " " (number->string h)"\n") out)
  (display (string-append "mur" " " (number->string xQ) " " (number->string (+ 10(+ yQ h))) " " (number->string (+ xQ 35)) " " (number->string (+ 15(+ yQ h))) "\n") out)
)
;hidrante
(define (hidrante hlIndice  hcIndice xH yH out)
  (display (string-append "h" " " "hnb0"(number->string hlIndice)"."(number->string hcIndice)".1" " " (number->string (+ xH)) " " (number->string (+ yH 90))"\n") out)
  (display (string-append "h" " " "hnb0"(number->string hlIndice)"."(number->string hcIndice)".2" " " (number->string (+ xH 65)) " " (number->string (+ yH 90))"\n") out)
  (display (string-append "h" " " "hnb0"(number->string hlIndice)"."(number->string hcIndice)".3" " " (number->string (+ xH 120)) " " (number->string (+ yH 90))"\n") out)
  (display (string-append "h" " " "hnb0"(number->string hlIndice)"."(number->string hcIndice)".4" " " (number->string (+ xH 120)) " " (number->string (+ yH 50))"\n") out))

(define (random-nslo);funcao random para circulos retangulos e textos
  (define face(list "n" "s" "l" "o"))
    (list-ref face(random 0 (length face))))

(define (random-crt );funcao random para circulos retangulos e textos
  (define x (list "c" "r" "t"))
   (list-ref x(random 0 (length x))) )

(define (random-cr);funcao referente para circulos e retangulos
  (define x (list "c" "r"))
    (list-ref x(random 0 (length x))))

(define (random-string);funcao que escolhe dentre 3 strings 
  (define strgAle(list "Primeira String Teste" "Teste Segunda String" "String Teste Terceira"))
   (list-ref stringAle(random 0 (length stringAle))) )
