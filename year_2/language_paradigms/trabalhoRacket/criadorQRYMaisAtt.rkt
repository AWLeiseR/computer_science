#lang racket
(require "moduloQry.rkt")
;le o geo
(define valorNX(leitura "file.geo"))

;definiçoes
(define max 5)
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
(define w (random 1 500))
(define h (random 1 500))
(define num1 (random 1 5))
(define num2 (random 1 5))
(define raizQ (inexact->exact (round (sqrt nq))))
(define raizH (inexact->exact (round (sqrt nh))))
(define raizS (inexact->exact (round (sqrt ns))))
(define raizR (inexact->exact (round (sqrt nr))))

(define o(comand1 i max))

(define i?(comand2 i max))

(define d(comand3 i max))

(define bb(comand4))

(define dq(comand5))

(define del(comand6 raizQ raizR raizS))

(define cbq(comand7 raizQ))

(define crd(comand8 raizQ raizR raizS))

(define trns(comand9 max))
