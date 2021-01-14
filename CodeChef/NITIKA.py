t = int(input())

for a in range(t):

	n = raw_input().split()
	o = []
	for x in n[:-1]:
		o.append(x[0].upper())
	o.append(n[-1][0].upper() + n[-1][1:].lower())
	print '. '.join(o)
