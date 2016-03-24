(load "prac42.scm")

(define ((repeat f count) x)
  (cond ((= 1 count) (f x))
		((even? count)
		 ((repeat (compose f f) (/ count 2)) x))
		(else
		 ((repeat f (- count 1)) (f x)))))
	   
