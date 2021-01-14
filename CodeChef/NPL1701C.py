t = int(input())

for z in range(t):
	n = int(input())
	a = map(int, raw_input().split())
	s = 0
	for x in a:
		n = 2
		while (x > 1):
			if x%n == 0:
				x/=n
				s+=1
			else:
				n += 1
	if s%2 == 0:
		print 'Friend'
	else:
		print 'Appu' 