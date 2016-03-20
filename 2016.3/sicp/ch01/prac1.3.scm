(define (bigger x y)
  (if (> x y)
	  x
	  y))
(define (smaller x y)
  (if (< x y)
	  x
	  y))
(define (sum-of-squares x y)
  (+
   (* x x)
   (* y y)))
(define (bigger-sum-of-squares x y z)
  (sum-of-squares (bigger x y)
				  (bigger (smaller x y) z)))
