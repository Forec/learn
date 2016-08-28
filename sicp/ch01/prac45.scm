(Load "prac43.scm")
(load "example1.3.3.scm")

(define (expt base n)
  (if (= n 0)
	  1
	  ((repeat (lambda (x) (* base x)) n) 1)))

(define (average-damp f)
  (lambda (x) (/ (+ x (f x)) 2)))

(define (average-damp-n-times f n)
  ((repeat average-damp n) f))

(define (damped-nth-root n damp-times)
  (lambda (x)
	(fix-point
	 (average-damp-n-times
	  (lambda (y)
		(/ x (expt y (- n 1))))
	  damp-times)
	 1.0)))

(define (lg n)
  (cond ((> (/ n 2) 1)
		 (+ 1 (lg (/ n 2))))
		((< (/ n 2) 1)
		 0)
		(else
		 1)))

(define (nth-root n)
  (damped-nth-root n (lg n)))
