(define (cons x y)
  (* (expt 2 x)
	 (expt 3 y)))

(define (car z)
  (cond ((= 0 z) 0)
		((= 0 (remainder z 2))
		 (+ 1 (car (/ z 2))))
		(else
		 0)))

(define (cdr z)
  (if (= 0 (remainder z 3))
	  (+ 1 (cdr (/ z 3)))
	  0))
