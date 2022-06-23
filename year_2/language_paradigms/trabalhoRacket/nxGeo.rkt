#lang racket
(provide (all-defined-out))


(define (funComeco n qQuadras nhh nss nrr npp nmm out cor1 cor2)
(display (string-append "nx" " " (number->string n) " " (number->string qQuadras) " " (number->string nhh) " "
(number->string nss) " " (number->string nrr) " " (number->string npp) " " (number->string npp)  "\n") out);coloca o nx no txt
(display (string-append "cq" " " cor1 " " "firebrick" " " (number->string 1.000) "\n") out) ;coloca o cq
(display (string-append "cs" " " "black" " " "yellow" " " (number->string 1.000) "\n") out) ;coloca o cs
(display (string-append "ch" " " "red" " " "firebrick" " " (number->string 1.000) "\n") out) ;coloca o ch
(display (string-append "cr" " " cor2 " " "black" " " (number->string 1.000) "\n") out)) ;coloca o cr