#!/usr/bin/env ruby

def quicksort(l)
	return l if !l or l.empty?
	pivot = l.shift
	smaller = l.select { |x| x < pivot }
	larger = l.select { |x| x >= pivot }
	return quicksort(smaller) + [pivot] + quicksort(larger)
end

puts quicksort(ARGV.collect{ |x| Integer(x)}).join(' ')