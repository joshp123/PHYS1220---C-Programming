## fartboner
import math

def main:
	input = []
	for x in xrange(1,10):
		input[x] = raw_input("Please enter integer number %d" % x)

	for x in xrange(1,10):
		print "Integer number " + repr(x) + " was " + repr(input[x])


	sum = floatNums = [float(x) for x in input]
	average = sum/len(input)
	print "The average of these numbers was " + repr(average)

	