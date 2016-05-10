;;; 30-square-tree

(define (square-tree tree)
  (cond ((null? tree)
		 '())
		((not (pair? tree))
		 (square tree))
		(else
		 (cons (square-tree (car tree))
			   (square-tree (cdr tree))))))

(define (map-square-tree tree)
  (map (lambda (sub-tree)
		 (if (pair? sub-tree)
			 (map-square-tree sub-tree)
			 (square sub-tree)))
		 tree))
						
