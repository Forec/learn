(load "prac02.scm")

(define (perimeter-rectangle r)
  (let ((length (length-of-rectangle r))
		(width (width-of-rectangle r)))
	(* 2
	   (+ length width))))
