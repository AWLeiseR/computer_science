#lang racket
(define in (open-input-file "file.geo"));abre o arquivo
(define nx(values (read-line in)));le a primeira linha
;funcao q tira o nx
(define (con a)
  (substring a 3))
;chama a funcao
(define a(con nx))
;divide a string em varias partes
(define b(string-split a))
;funcao que transforma string em numero
(define (num a)
  (string->number a))
;aplica a funcao num em todos os elementos da lista de strings(b)
(define valorNX (map num b))

(define max 5)
(define i (car valorNX))
(define nq (car (cdr valorNX)))
(define nh (car (cdr (cdr valorNX))))
(define ns (car (cdr (cdr (cdr valorNX)))))
(define nr (car (cdr (cdr (cdr (cdr valorNX))))))

(close-input-port in)

(define j (random i))
(define k (random i))
(define x (random 1 500))
(define y (random 1 500))

(define out1 (open-output-file "q-o.qry"))
(define (funcWhileo n)
  (set! j(random i))
  (set! k(random i))
  (cond
  [(= j k) (set! j(random i))])
  (display (string-append "o?" " " (number->string j) " " (number->string k)"\n") out1)
  (cond
    [(> n 0) (funcWhileo (- n 1))]
    [else (print "acabou func o")]))
(define resultadoo (funcWhileo max))
(close-output-port out1)

(define out2 (open-output-file "q-i.qry"))
(define (funcWhilei n)
  (set! j(random i))
  (set! x(random 500))
  (set! y(random 500))
  (display (string-append "i?" " " (number->string j) " " (number->string x) " " (number->string y) "\n") out2)
  (cond
    [(> n 0) (funcWhilei (- n 1))]
    [else (print "acabou func i")]))
(define resultadoi (funcWhilei max))
(close-output-port out2)

(define out3 (open-output-file "q-d.qry"))
(define (funcWhiled n)
  (set! j(random i))
  (set! k(random i))
  (cond
  [(= j k) (set! j(random i))])
  (display (string-append "d?" " " (number->string j) " " (number->string k)"\n") out3)
  (cond
    [(> n 0) (funcWhiled (- n 1))]
    [else (print "acabou func d")]))
(define resultado (funcWhiled max))
(close-output-port out3)

(define out4 (open-output-file "q-bb.qry"))
(define sufixo "bbsuf01")
(define corbb "red")
(display (string-append "bb" " " sufixo " " corbb "\n") out4)
(close-output-port out4)

(define out7 (open-output-file "q-cbq.qry"))
(define (funcWhil n)
  (define corcbq "green")
  (define r (random 1 500))
  (set! x (random 1 500))
  (set! y (random 1 500))
  (display (string-append "trns" " "(number->string x) " "(number->string y) " " (number->string r) " " corcbq"\n") out7)
  (cond
    [(> n 0) (funcWhil (- n 1))]
    [else (print "acabou func cbq")]))
(define resultado1 (funcWhil max))
(close-output-port out7)

(define out9 (open-output-file "q-trns.qry"))
(define (funcWhi n)
  (define w (random 1 500))
  (define h (random 1 500))
  (set! x (random 1 500))
  (set! y (random 1 500))
  (define dx (random -300 300))
  (define dy (random -300 300))
  (display (string-append "trns" " "(number->string x) " "(number->string y) " " (number->string w) " "(number->string h) " "(number->string dx) " "(number->string dy) "\n") out9)
  (cond
    [(> n 0) (funcWhi (- n 1))]
    [else (print "acabou func trns")]))
(define resultado2 (funcWhi max))
(close-output-port out9)
