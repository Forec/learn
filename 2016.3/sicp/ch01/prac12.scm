(define (pascal row col)
  (cond ((> col row)
		 (error "unvalid row value"))
		 ((or (= col 0) (= row col))
		  1)
		 (else (+ (pascal (- row 1) (- col 1))
				  (pascal (- row 1) col)))))

(define (factorial n)
  (fact-iter 1 1 n))

(define (fact-iter product counter max-count)
  (if (> counter max-count)
	  product
	  (fact-iter (* counter product)
				 (+ counter 1)
				 max-count)))

(define (pascal2 row col)
  (/ (factorial row)
	 (* (factorial col)
		(factorial (- row col)))))
