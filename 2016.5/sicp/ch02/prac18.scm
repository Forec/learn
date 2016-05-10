(define (reverse1 items)
  (if (null? items)
	  ('())
	  (cons (reverse (cdr items))
			(car items))))

(define (reverse items)
  (define (iter remainded-items result)
	(if (null? remainded-items)
		result
		(iter (cdr remainded-items)
			  (cons (car remainded-items) result))))
  (iter items '()))
