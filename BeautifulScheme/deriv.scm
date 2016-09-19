(define (deriv exp var)
  (cond ((number? exp)
		0)
		((variable? exp)
		 (if (same-variable? exp var)
			 1
			 0))
		((sum? exp)
		 (make-sum (deriv (addend exp) var)
				   (deriv (augend exp) var)))
		((sub? exp)
		 (make-sub (deriv (subed exp) var)
				   (deriv (suber exp) var)))
		((product? exp)
		 (make-sum
		  (make-product (multiplier exp)
						(deriv (multiplicand exp) var))
		  (make-product (deriv (multiplier exp) var)
						(multiplicand exp))))
		((divide? exp)
		 (make-divide (make-sub (make-product (deriv (divided exp) var) (divider exp))
								(make-product (deriv (divider exp) var) (divided exp)))
					  (make-product (divider exp) (divider exp))
		  ))
		((exponentiation? exp)
		 (let ((n (exponent exp))
			   (u (base exp)))
		   (make-product
			n
			(make-product
			 (make-exponentiation
			  u
			  (- n 1))
			 (deriv u var)))))
		(else
		 (error "unknown expression type -- DERIV" exp))))

;; exponentiation
(define (make-exponentiation base exponent)
  (cond ((= exponent 0)
		 1)
		((= exponent 1)
		 base)
		(else
		 (list '** base exponent))))

(define (exponentiation? x)
  (and (pair? x)
	   (eq? (car x) '**)))

(define (base exp)
  (cadr exp))

(define (exponent exp)
  (caddr exp))

;; number
(define (=number? exp num)
   (and (number? exp)
		(= exp num)))


;; variable
(define (variable? x)
  (symbol? x))

(define (same-variable? v1 v2)
  (and (variable? v1)
	   (variable? v2)
	   (eq? v1 v2)))

;; sum
(define (make-sum a1 a2)
	(cond ((=number? a1 0)
		   a2)
		  ((=number? a2 0)
		   a1)
		  ((and (number? a1) (number? a2))
		   (+ a1 a2))
		  (else
		   (list a1 '+ a2))))

(define (sum? x)
  (and (pair? x)
	   (eq? (cadr x) '+)))

(define (addend s)
  (car s))

(define (augend s)
  (caddr s))

;; sub
(define (make-sub a1 a2)
  (cond ((=number? a2 0)
		 a1)
		((and (number? a1) (number? a2))
		 (- a1 a2))
		(else
		 (list a1 '- a2))))

(define (sub? x)
  (and (pair? x)
	   (eq? (cadr x) '-)))

(define (subed s)
  (car s))

(define (sube s)
  (caddr s))

;; product
(define (make-product m1 m2)
	(cond ((or (=number? m1 0) (=number? m2 0))
		   0)
		  ((=number? m1 1)
		   m2)
		  ((=number? m2 1)
		   m1)
		  ((and (number? m1) (number? m2))
		   (* m1 m2))
		  (else
		   (list m1 '* m2))))

(define (product? x)
  (and (pair? x)
	   (eq? (cadr x) '*)))

(define (multiplier p)
  (car p))

(define (multiplicand p)
  (caddr p))

;; divide
(define (make-divide m1 m2)
  (cond ((=number? m2 0)
		 (error "divided by 0"))
		((=number? m1 0)
		 0)
		((=number? m2 1)
		 m1)
		((and (number? m1) (number? m2))
		 (/ m1 m2))
		(else
		 (list m1 '/ m2))))

(define (divide? x)
  (and (pair? x)
	   (eq? (cadr x) '/)))

(define (divided d)
  (car d))

(define (divider d)
  (caddr d))
