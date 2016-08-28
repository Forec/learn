(load "prac37.scm")

(define (tan-cf x k)
  (define (N i)
	(if (= 1 i)
		x
		(- (* x x))))
  (define (D i)
	(- (* 2 i) 1))

  (exact->inexact (cont-frac1 N D k)))
		
