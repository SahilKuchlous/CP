t = int(input())

for z in range(t):

	n, q = map(int, raw_input().split())

	l = map(int, raw_input().split())

	for y in range(q):

		k = int(input())
		c = 0
		s = 0
		e = 0

		lcf = filter(lambda x: x < k, l)
		c += len(l) - len(lcf)

		lcf = sorted(lcf, reverse = True)
		while (s+e+1 < len(lcf)):
			e += 1
			lcf[s] += 1
			if lcf[s] == k:
				s += 1
				c += 1	

		print c
