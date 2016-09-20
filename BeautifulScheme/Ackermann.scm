;; Ackermann

(define (A x y)
  (cond ((= y 0) 0)
		((= x 0) (* 2 y))
		((= y 1) 2)
		(else (A (- x 1)
				 (A x (- y 1))))))

(define (Ackermann x y)
  (cond ((= x 0) (+ y 1))
		((= y 0) (Ackermann (- x 1) 1))
		(else
		 (Ackermann (- x 1)
					(Ackermann x (- y 1))))))

;; (A 0 n) = 2 * n
;; (A 1 n) = 2 ^ n
;; (A 2 n) = 2 ^ (2 ^ (n-1))
;; (A 3 1) = 2 = 2 ^ 1
;; (A 3 2) = 4 = 2 ^ 2
;; (A 3 3) = 65536 = 2 ^ 16

;; phi
(define (phi m n p)
  (cond ((= p 0) (+ m n))
		((and (= n 0) (= p 1)) 0)
		((and (= n 0) (= p 2)) 1)
		((and (= n 0) (> p 2)) m)
		((and (> n 0) (> p 0)) (phi m (phi m (- n 1) p) (- p 1)))))
