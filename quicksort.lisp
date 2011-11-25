#!/usr/bin/sbcl --script

(defun quicksort(l &optional pivot smaller larger)	
	(cond 
		((and (eq l nil) (eq pivot nil)) l)
		((eq l nil) (concatenate 'list (quicksort smaller) (list pivot) (quicksort larger)))
		((eq pivot nil) (quicksort (rest l) (first l)))
		((< (first l) pivot)	(quicksort (rest l) pivot (cons (first l) smaller) larger))
		(T (quicksort (rest l) pivot smaller (cons (first l) larger)))))

(format T "~{~a~^ ~}~%" (quicksort (mapcar 'parse-integer (rest *posix-argv*))))
