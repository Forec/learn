(load "prac23.scm")

(define (filtered-accumulate combine null-value term a next b valid?)
  (if (> a b)
	  null-value
	  (let ((rest-terms (filtered-accumulate combine
											 null-value
											 term
											 (next a)
											 next
											 b
											 valid?)))
		(if (valid? a)
			(combine (term a) rest-terms)
			rest-terms))))

(define (primes-sum a b)
  (filtered-accumulate +
					   0
					   (lambda (x) x)
					   a
					   (lambda (i) (+ i 1))
					   b
					   prime?))
							  
(define (coprime? i n)
  (and (< i n)
	   (= 1 (gcd i n))))

(define (product-of-coprimes n)
  (filtered-accumulate *
					   1
					   (lambda (x) x)
					   1
					   (lambda (i) (+ i 1))
					   n
					   (lambda (x) (coprime? x n))))
(define (filtered-accumulate1 combine null-value term a next b valid?)
  (define (iter i result)
	(cond ((> i b)
		   result)
		  ((valid? i)
		   (iter (next i) (combine (term i) result)))
		  (else
		   (iter (next i) result))))
  (iter a null-value))
