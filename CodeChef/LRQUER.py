t = int(input())
for z in range(t):
	n, q = map(int, raw_input().split())
	a = map(int, raw_input().split())
	for x in range(q):
		opp = map(int, raw_input().split())
		if opp[0] == 1:
			l = opp[1]-1
			r = opp[2]-1
			a1 = a[l+1:r]
			gs = 0
			for m in a1:
				s = (m - a[l]) * (a[r] - m)
				if s > gs:
					gs = s
			print gs
		elif opp[0] == 2:
			a[opp[1]-1] = opp[2]