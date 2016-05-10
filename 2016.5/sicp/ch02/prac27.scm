(define (deep-reverse tree)
  (cond ((null? tree)
		 '())
		((not (pair? tree))
		 tree)
		(else
		 (reverse (list (deep-reverse (car tree))
						(deep-reverse (cadr tree)))))))

(define (tree-reverse tree)
  (define (iter remainded-items result)
	(if (null? remainded-items)
		result
		(iter (cdr remainded-items)
			  (cons (if (pair? (car remainded-items))
						(tree-reverse (car remainded-items))
						(car remainded-items))
					result))))
  (iter tree '()))
