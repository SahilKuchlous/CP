import random

r = 2500
c = 2500

strings = []
for i in xrange(r):
	for j in xrange(c):
		if random.randrange(0, 10) > 2:
			strings.append(str(i) + " " + str(j))


print len(strings)
for s in strings:
	print s