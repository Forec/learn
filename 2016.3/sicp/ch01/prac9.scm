(define (plus a b)
  (if (= a 0)
	  b
	  (plus (dec a) (inc b))))

(define (dec x)
  (- x 1))

(define (inc x)
  (+ x 1))
