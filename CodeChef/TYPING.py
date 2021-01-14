t = int(input())
for z in xrange(t):
	n = int(input())
	encountered = {}
	g1 = {'d', 'f'}
	g2 = {'j', 'k'}
	last = ''
	total = 0
	for x in xrange(n):
		word = 0
		s = raw_input()
		if s in encountered:
			total += encountered[s]/2
		else:
			last = s[0]
			word += 2
			for y in s[1:]:
				if {y, last} == g1 or {y, last} == g2 or y == last:
					word += 4
				else:
					word += 2
				last = y
			encountered[s] = word
			total += word
	print total