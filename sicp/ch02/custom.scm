;;; filter, enumerate, map, accumulate

(define (mapp f sequence)
  (if (null? sequence)
	  '()
	  (cons (f (car sequence))
			(mapp f (cdr sequence)))))

(define (filterr f sequence)
  (cond ((null? sequence)
		 '())
		((f (car sequence))
		 (cons (car sequence)
			   (filterr f (cdr sequence))))
		(else
		 (filterr f (cdr sequence)))))

(define (accumulate op initial sequence)
  (if (null? sequence)
	  initial
	  (op (car sequence)
		  (accumulate op initial (cdr sequence)))))

(define (enumeratee low high)
  (if (> low high)
	  '()
	  (cons
	   low
	   (enumeratee (+ low 1) high))))
		  
