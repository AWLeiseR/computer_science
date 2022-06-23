#lang racket
(provide (all-defined-out))

;funcao transforma string em num
(define (num a)
  (string->number a))

;funca de leitura geo
(define (leitura arq)
  (define in (open-input-file arq));abre o arquivo
  (define nx(values (read-line in)));le a primeira linha
  (close-input-port in)
  ;comando q tira o nx
  (define semNX(substring nx 3))
  ;divide a string em varias partes
  (define aux(string-split semNX))
;aplica a funcao num em todos os elementos da lista de strings(b)
  (map num aux)
  )

;random string
(define (random-string)
  (define x(random 4))
    (cond [(equal? x 0) "b0"]
          [(equal? x 1) "hnb0"]
          [(equal? x 2) "rbb0"]
          [(equal? x 3) "sfb0"]
          ))

;comando 1
(define (comand1 i max)
(define out1 (open-output-file "qry/q-o.qry"))
(define (funcWhileo n)
  (define j(random 1 i))
  (define k(random 1 i))
  (cond
  [(= j k) (set! j(random 1 i))])
  (display (string-append "o?" " " (number->string j) " " (number->string k)"\n") out1)
  (cond
    [(> n 0) (funcWhileo (- n 1))]
    ))
(define resultadoo (funcWhileo max))
(close-output-port out1))

;comando 2
(define (comand2 i max)
(define out2 (open-output-file "qry/q-i.qry"))
(define (funcWhilei n)
  (define j(random 1 i))
  (define x(random 1 1000))
  (define y(random 1 1000))
  (display (string-append "i?" " " (number->string j) " " (number->string x) " " (number->string y) "\n") out2)
  (cond
    [(> n 0) (funcWhilei (- n 1))]
    ))
(define resultadoi (funcWhilei max))
(close-output-port out2))

;comando 3
(define (comand3 i max)
(define out3 (open-output-file "qry/q-d.qry"))
(define (funcWhiled n)
  (define j(random 1 i))
  (define k(random 1 i))
  (cond
  [(= j k) (set! j(random 1 i))])
  (display (string-append "d?" " " (number->string j) " " (number->string k)"\n") out3)
  (cond
    [(> n 0) (funcWhiled (- n 1))]
    ))
(define resultado (funcWhiled max))
(close-output-port out3))

;comando 4
(define (comand4)
(define out4 (open-output-file "qry/q-bb.qry"))
(define sufixo "bbsuf01")
(define corbb "red")
(display (string-append "bb" " " sufixo " " corbb "\n") out4)
(close-output-port out4))

;comando dq
(define (comand5)
(define out5 (open-output-file "qry/q-dq.qry"))
(define metricaL1 "L1")
(define metricaL2 "L2")
(define r 500)
(define stringaledq "rbb01.2")
(display (string-append "dq" " " metricaL2 " " stringaledq " " (number->string r)"\n") out5)
(set! r 200)
(set! stringaledq "sfb04.3")
(display (string-append "dq" " " metricaL1 " " stringaledq " " (number->string r)"\n") out5)
(set! r 100)
(set! stringaledq "hnb02.3.4")
(display (string-append "dq" " " metricaL1 " " stringaledq " " (number->string r)"\n") out5)
(close-output-port out5))

;comando del
(define (comand6 raizQ raizR raizS)
(define out6 (open-output-file "qry/q-del.qry"))
(define num1 (random 1 raizQ))
(define num2 (random 1 raizQ))
(define hidin (random 1 5))
(display (string-append "del" " " "b0" (number->string num1) "." (number->string num2)"\n") out6)
(set! num1 (random 1 raizQ))
(set! num2 (random 1 raizQ))
(display (string-append "del" " " "hnb0" (number->string num1) "." (number->string num2) "." (number->string hidin)"\n") out6)
(set! num1 (random 1 raizR))
(set! num2 (random 1 raizR))
(display (string-append "del" " " "rbb0" (number->string num1) "." (number->string num2)"\n") out6)
(set! num1 (random 1 raizS))
(set! num2 (random 1 raizS))
(display (string-append "del" " " "sfb0"(number->string num1) "." (number->string num2)"\n") out6)
(close-output-port out6))

;comando cbq
(define (comand7 raizQ)
(define out7 (open-output-file "qry/q-cbq.qry"))
(define (funcWhilecbq n)
  (define corcbq "green")
  (define r 300)
  (define x 20)
  (define y 20)
  (display (string-append "cbq" " " (number->string x) " "(number->string y) " " (number->string r) " " "green" "\n") out7)
  (set! r 100)
  (set! x (* 3 100))
  (set! y (* 3 240))
  (display (string-append "cbq" " " (number->string x) " "(number->string y) " " (number->string r) " " "green" "\n") out7)
  (set! r 1000)
  (set! x (* raizQ 240))
  (set! y (* raizQ 240))
  (display (string-append "cbq" " " (number->string x) " "(number->string y) " " (number->string r) " " "yellow" "\n") out7)
  (cond
    [(> n 0) (funcWhilecbq (- n 1))]
    ))
(define resultado1 (funcWhilecbq 0))
(close-output-port out7))

;comando crd
(define (comand8 raizQ raizR raizS)
(define out8 (open-output-file "qry/q-crd.qry"))
(define stringalecrd (random-string))
(define num1 (random 1 raizQ))
(define num2 (random 1 raizQ))
(define hidin (random 1 5))
(display (string-append "crd?" " " "b0" (number->string num1) "." (number->string num2)"\n") out8)
(set! num1 (random 1 raizQ))
(set! num2 (random 1 raizQ))
(display (string-append "crd?" " " "hnb0" (number->string num1) "." (number->string num2) "." (number->string hidin)"\n") out8)
(set! num1 (random 1 raizR))
(set! num2 (random 1 raizR))
(display (string-append "crd?" " " "rbb0" (number->string num1) "." (number->string num2)"\n") out8)
(set! num1 (random 1 raizS))
(set! num2 (random 1 raizS))
(display (string-append "crd?" " " "sfb0"(number->string num1) "." (number->string num2)"\n") out8)
(close-output-port out8))

;comando trns
(define (comand9 max)
(define out9 (open-output-file "qry/q-trnscima.qry"))
(define (funcWhiletrns n)
  (define w 270)
  (define h 480)
  (define x 20)
  (define y 20)
  (define dx 0)
  (define dy -200)
  (display (string-append "trns" " "(number->string x) " "(number->string y) " " (number->string w) " "(number->string h) " "(number->string dx) " "(number->string dy) "\n") out9)
  (cond
    [(> n 0) (funcWhiletrns (- n 1))]
    ))
(define resultado2 (funcWhiletrns 0))
(close-output-port out9))

(define (comand10 max raizQ)
(define out10 (open-output-file "qry/q-trnsdir.qry"))
(define (funcWhiletrnsdir n)
  (define w 1000)
  (define h 500)
  (define x (* raizQ 0.5))
  (define y (* raizQ 0.5))
  (define dx 350)
  (define dy 50)
  (display (string-append "trns" " "(number->string x) " "
                          (number->string y) " " (number->string w) " "
                          (number->string h) " "(number->string dx) " "
                          (number->string dy) "\n") out10)
  (cond
    [(> n 0) (funcWhiletrnsdir (- n 1))]
    ))
  (define resultadotrnsdir (funcWhiletrnsdir 0))
(close-output-port out10))

(define (comand15 max raizQ)
(define out15 (open-output-file "qry/q-trnsesq.qry"))
(define (funcWhiletrnsdir n)
  (define w 1000)
  (define h 500)
  (define x (* raizQ 0.5))
  (define y (* raizQ 0.5))
  (define dx 350)
  (define dy 50)
  (display (string-append "trns" " "(number->string x) " "(number->string y) " " (number->string w) " "(number->string h) " "(number->string dx) " "(number->string dy) "\n") out15)
  (cond
    [(> n 0) (funcWhiletrnsdir (- n 1))]
    ))
  (define resultadotrnsdir (funcWhiletrnsdir 0))
(close-output-port out15))

;comando fh
(define (comand11 nh raizQ)
  (define out11 (open-output-file "qry/q-fh.qry"))
  (define prox(list "-" "+"))
  (define k(random 0 nh))
  (define face(list "n" "s" "l" "o"))
  (define cep "b0")
  (define cepnum(random 0 raizQ))
  (define cepnum2(random 0 raizQ))
  (display(string-append (list-ref prox(random 0 (length prox)))"" (number->string k) " "
                         cep (number->string cepnum)"."(number->string cepnum2) " "
                         (list-ref face(random 0 (length face)))" " "\n")out11)
  
  (close-output-port out11))

;comando fs
(define (comand12 ns raizQ)
  (define out12 (open-output-file "qry/q-fs.qry"))
  (define k(random 0 ns))
  (define face(list "n" "s" "l" "o"))
  (define cep "b0")
  (define cepnum(random 0 raizQ))
  (define cepnum2(random 0 raizQ))
  (display(string-append (number->string k) " " cep (number->string cepnum)"."
                         (number->string cepnum2) " " (list-ref face(random 0 (length face)))" " )out12)
  (close-output-port out12))

;comando fi
(define(comand13 ns)
(define out13 (open-output-file "qry/q-fi.qry"))
(define x (random 1 500))
(define y (random 1 500))
(define sem (random 1 ns))
(define raio (random 1 300))
(display (string-append "fi" " "(number->string x) " " (number->string y) " "
                        (number->string sem) " " (number->string raio)" " "\n") out13)
  
(close-output-port out13))

;comando brl
(define (comand14)
(define out14 (open-output-file "qry/q-brl.qry"))
(define x (random 1 500))
(define y (random 1 500))
(display (string-append "brl" " "(number->string x) " " (number->string y)"\n") out14)
(close-output-port out14))