(define (for-each p lst)
  (if (not (null? lst))
	  (begin
		(p (car lst))
		(for-each p (cdr lst)))))
