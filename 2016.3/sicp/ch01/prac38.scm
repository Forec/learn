(load "prac37.scm")

(define (e k)
  (define (N i)
	1)
  (define (D i)
	(if (= 0 (remainder (+ i 1) 3))
		(* 2 (/ (+ i 1) 3))
		1))
  (+ 2.0
	 (cont-frac1 N D k)))
