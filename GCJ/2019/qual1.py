t = int(input())
for z in range(t):
	n = raw_input()
	a = ''
	b = ''
	for x in n:
		if x == '4':
			a += '2'
			b += '2'
		else:
			a += '0'
			b += x
	print 'Case #' + str(z+1) + ': ' + str(int(a)) + ' ' + str(int(b))