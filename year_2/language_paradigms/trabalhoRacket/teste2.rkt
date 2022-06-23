#lang racket
(require "conds.rkt")
;(provide (all-defined-out))
;(provide Cond1)


(define yInicio 0)
(define xInicio 10)
(define xQuadra 0)
(define yQuadra 10)
(define qBaixo 20)
(define quantTotalQuad 1)
(define intervalo 50)
(define qDir  1)

(set! yInicio (Cond1 qDir yInicio intervalo))
(set! xQuadra (Cond2 qDir xInicio xQuadra))
(set! yQuadra (Cond3 qDir  yInicio yQuadra))
(set! qBaixo (cond4  qDir  qBaixo))
(set! quantTotalQuad (Cond6 qDir quantTotalQuad))