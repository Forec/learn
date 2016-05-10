;;; 33-accumulate

(load "custom.scm")

(define (mapp p sequence)
  (accumulate (lambda (x y)
				(cons (p x) y))
			  '()
			  sequence))

(define (appendd list1 list2)
  (accumulate cons list2 list1))

(define (length sequence)
  (accumulate (lambda (x y)
				(+ 1 y))
			  0
			  sequence))
