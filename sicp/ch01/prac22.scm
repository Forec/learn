(define (next-odd n)
  (if (odd? n)
	  (+ 2 n)
	  (+ 1 n)))

(define (smallest-divisor n)
  (define (find-divisor n test-divisor)
	(define (divides? a b)
	  (= 0 (remainder b a)))
	(cond ((> (square test-divisor) n)
		   n)
		  ((divides? test-divisor n)
		   test-divisor)
		  (else
		   (find-divisor n (+ 1 test-divisor)))))
  (find-divisor n 2))

(define (prime? n)
  (= n (smallest-divisor n)))

(define (continue-primes n count)
  (cond ((= count 0)
		 (display "are primes."))
		((prime? n)
		 (display n)
		 (newline)
		 (continue-primes (next-odd n) (- count 1)))
		(else
		 (continue-primes (next-odd n) count))))

(define (search-for-primes n)
  (let ((start0time (real-time-clock)))
	(continue-primes n 3)
	(- (real-time-clock) start0time)))
