#lang racket
(define in (open-input-file "fileQuadra2.geo"));abre o arquivo
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