t = int(input())

for z in range(t):

	n = int(input())
	towers = map(int, raw_input().split())
	dslopes = [1]
	uslopes = [1]

	for t in range(1, n-1):
		uslopes.append(min(uslopes[t-1]+1, towers[t]))
	uslopes.append(1)

	for t in range(1, n-1):
		dslopes.append(min(dslopes[t-1]+1, towers[n-(t+1)]))
	dslopes.append(1)
	dslopes = dslopes[::-1]

	ranks = [min(dslopes[t], uslopes[t]) for t in range(n)]
	
	bestHeight = 0
	bestCenter = 0
	for t in range(n):
		if ranks[t] > bestHeight:
			bestHeight = ranks[t]
			bestCenter = t

	r = 0
	for t in range(n):
		if bestCenter - bestHeight < t < bestCenter + bestHeight:
			r += towers[t] - (bestHeight - abs(bestCenter-t))
		else:
			r += towers[t]
	print r