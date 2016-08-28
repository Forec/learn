(define (divides? test-divisor n)
  (= 0 (remainder n test-divisor)))

(define (next-odd n)
  (if (= 1 (remainder n 2))
	  (+ 2 n)
	  (+ 1 n)))

(define (next n)
  (if (= n 2)
	  3
	  (+ n 2)))

(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n)
		 n)
		((divides? test-divisor n)
		 test-divisor)
		(else
		 (find-divisor n (next test-divisor)))))

(define (smallest-divisor n)
  (find-divisor n 2))

(define (prime? n)
  (= (smallest-divisor n) n))

(define (search-for-primes n count)
  (cond ((= count 0)
		 (display "are primes"))
		((prime? n)
		 (display n)
		 (newline)
		 (search-for-primes (next-odd n) (- count 1)))
		(else
		 (search-for-primes (next-odd n) count))))

(define (time-primes n)
  (let ((start-time (real-time-clock)))
	(search-for-primes n 3)
	(- (real-time-clock) start-time)))
