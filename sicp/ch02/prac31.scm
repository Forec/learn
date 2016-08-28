;;; 31-abstract

(define (tree-map f tree)
  (cond ((null? tree)
		 '())
		((not (pair? tree))
		 (f tree))
		(else
		 (cons (tree-map f (car tree))
			   (tree-map f (cdr tree))))))

(define (tree-map2 f tree)
  (map (lambda (sub-tree)
		 (if (pair? sub-tree)
			 (tree-map2 f sub-tree)
			 (f sub-tree)))
	   tree))
