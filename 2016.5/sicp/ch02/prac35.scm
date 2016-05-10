(load "custom.scm")
(define (count-leaves tree)
  (accumulate +
			  0
			  (map (lambda (sub-tree)
					 (if (pair? sub-tree)
						 (count-leaves sub-tree)
						 1))
				   tree)))
