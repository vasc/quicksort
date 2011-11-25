#!/usr/bin/env python

import sys

def quicksort(l):
	if not l: return l
	pivot = l[0]
	smaller = [x for x in l[1:] if x < pivot]
	larger = [x for x in l[1:] if x >= pivot]
	return quicksort(smaller) + [pivot] + quicksort(larger)

l = map(int, sys.argv[1:])

print " ".join(map(str, quicksort(l)))

