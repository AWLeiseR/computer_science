(display "Input: ")
(define a (read-line (current-input-port) 'any))
(printf "input: ~a, length: ~a, last character: ~a\n"
        a
        (string-length a)
        (char->integer (string-ref a (- (string-length a) 1))))