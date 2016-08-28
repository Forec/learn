(load "prac43.scm")

(define dx 0.00001)

(define (smooth f)
  (lambda (x)
	(/ (+ (f (- x dx))
		  (f x)
		  (f (+ x dx)))
	   3)))

(define (smooth-n-times f n)
  (define (iter i smooth-f)
	(if (= i 0)
		smooth-f
		(iter (- i 1)
			  (smooth smooth-f))))
  (iter n f))

(define (smooth-n-times1 f n)
  (let ((n-times-smooth (repeat smooth n)))
	(n-times-smooth f)))
