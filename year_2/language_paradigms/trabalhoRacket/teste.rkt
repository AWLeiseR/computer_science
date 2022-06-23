#lang racket



;funcoes
;leitrua do geo
(define (leitura arquivo)
  (define in (open-input-file arquivo));abre o arquivo
  (define nx(values (read-line in)));le a primeira linha
  ( close-input-port in)
  (define valor(substring nx 3))
  (string-split valor))
;transforma string em numero
(define (num a)
  (string->number a))
;retorna uma string aleatoria
(define (random-string x)
  (set! x (random 4))
    (cond [(equal? x 0) "b0"]
          [(equal? x 1) "hnb0"]
          [(equal? x 2) "rbb0"]
          [(equal? x 3) "sfb0"]
          ))
;funcao primeiro comando

(define (comand1 arq n)
(define out1 (open-output-file arq))
(define (funcWhileo n)
  (set! j(random i))
  (set! k(random i))
  (cond
  [(= j k) (set! j(random i))])
  (display (string-append "o?" " " (number->string j) " " (number->string k)"\n") out1)
  (printf (string-append "o?" " " (number->string j) " " (number->string k)"\n"))
  (cond
    [(> n 0) (funcWhileo (- n 1))]
    [else (print "acabou func o")]))
(close-output-port out1))

;Main
;chama a funcao que le o geo (define resultadoo (funcWhileo max))
(define nx(leitura "file.geo"))
;funcao que transforma string em numero
(define valorNX (map num nx))
(define i (car valorNX))
(define nq (car (cdr valorNX)))
(define nh (car (cdr (cdr valorNX))))
(define ns (car (cdr (cdr (cdr valorNX)))))
(define nr (car (cdr (cdr (cdr (cdr valorNX))))))
(define j (random i))
(define k (random i))
(define x (random 1 500))
(define y (random 1 500))
(define r (random 1 500))
(define num1 (random 1 5))
(define num2 (random 1 5))
(define max 5)
(define o? (comand1 "q-o.qry" max));chama funcao para o primeiro comando

  ;funcao q tira o nx
;(define (con a)
  ;(substring a 3))
;chama a funcao
;(define a(con nx))

  ;divide a string em varias partes
;(define b(string-split a))

;aplica a funcao num em todos os elementos da lista de strings(b)
#|(define max 5)
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
(define r (random 1 500))
(define num1 (random 1 5))
(define num2 (random 1 5))
(define (random-string x)
  (set! x (random 4))
    (cond [(equal? x 0) "b0"]
          [(equal? x 1) "hnb0"]
          [(equal? x 2) "rbb0"]
          [(equal? x 3) "sfb0"]
          ))

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
  (set! x(random 1 500))
  (set! y(random 1 500))
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
    [else (print "acabou func")]))
(define resultado (funcWhiled max))
(close-output-port out3)

(define out4 (open-output-file "q-bb.qry"))
(define sufixo "bbsuf01")
(define corbb "red")
(display (string-append "bb" " " sufixo " " corbb "\n") out4)
(close-output-port out4)

(define out5 (open-output-file "q-dq.qry"))
(set! num1 (random 1 5))
(set! num2 (random 1 5))
(define metricaL1 "L1")
(define metricaL2 "L2")
(define stringaledq (random-string 0))
(display (string-append "dq" " " metricaL1 " " (string-append stringaledq (number->string num1) "." (number->string num2)) " " (number->string r)"\n") out5)
(set! stringaledq (random-string 0))
(set! num1 (random 1 5))
(set! num2 (random 1 5))
(display (string-append "dq" " " metricaL2 " " (string-append stringaledq (number->string num1) "." (number->string num2)) " " (number->string r)"\n") out5)
(close-output-port out5)

(define out6 (open-output-file "q-del.qry"))
(set! num1 (random 1 5))
(set! num2 (random 1 5))
(display (string-append "del" " " "b0" (number->string num1) "." (number->string num2)"\n") out6)
(set! num1 (random 1 5))
(set! num2 (random 1 5))
(display (string-append "del" " " "hnb0" (number->string num1) "." (number->string num2)"\n") out6)
(set! num1 (random 1 5))
(set! num2 (random 1 5))
(display (string-append "del" " " "rbb0" (number->string num1) "." (number->string num2)"\n") out6)
(set! num1 (random 1 5))
(set! num2 (random 1 5))
(display (string-append "del" " " "sfb0"(number->string num1) "." (number->string num2)"\n") out6)
(close-output-port out6)

(define out7 (open-output-file "q-cbq.qry"))
(define (funcWhilecbq n)
  (define corcbq "green")
  (define r (random 1 500))
  (set! x (random 1 500))
  (set! y (random 1 500))
  (display (string-append "cbq" " "(number->string x) " "(number->string y) " " (number->string r) " " corcbq"\n") out7)
  (cond
    [(> n 0) (funcWhilecbq (- n 1))]
    [else (print "acabou func")]))
(define resultado1 (funcWhilecbq max))
(close-output-port out7)

(define out8 (open-output-file "q-crd.qry"))
(define stringalecrd (random-string 0))
(set! num1 (random 1 5))
(set! num2 (random 1 5))
(display (string-append "crd?" " " stringalecrd (number->string num1) "." (number->string num2)"\n") out8)
(close-output-port out8)

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

(define out10 (open-output-file "q-brl.qry"))
(set! x (random 1 500))
(set! y (random 1 500))
(display (string-append "brl" " "(number->string x) " " (number->string y)"\n") out10)
(close-output-port out10)

(define out11 (open-output-file "q-fi.qry"))
(set! x (random 1 500))
(set! y (random 1 500))
(define sem (random 1 ns))
(define raio (random 1 300))
(display (string-append "fi" " "(number->string x) " " (number->string y) " " (number->string sem) " " (number->string raio)" " "\n") out11)
(close-output-port out11)|#