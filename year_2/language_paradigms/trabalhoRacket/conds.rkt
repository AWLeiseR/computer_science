#lang racket
(provide (all-defined-out))

(define (Cond1 qDir yInicio intervalo)
  (if (< qDir 0)
       yInicio
         (+  yInicio intervalo)))

(define (Cond2 qDir  xInicio xQuadra)
  (if (< qDir 0)
      xInicio
      xQuadra))

(define (Cond3 qDir  yInicio yQuadra)
  (if (< qDir 0)
      yInicio
      yQuadra))

(define (cond4  qDir  qBaixo)
  (if (< qDir 0)
      (+ qBaixo 1)
      qBaixo))

(define (Cond6 qDir quantTotalQuad)
  (if (< qDir 0)
      (- quantTotalQuad 1)
      qDir))