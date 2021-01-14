t = int(input())

for z in range(t):

	n, m = map(int, raw_input().split())
	codes = raw_input().split()
	con = {}
	for x in range(n):
		sub = raw_input().split()
		name = sub[0]
		code = sub[1]
		score = int(sub[2])
		if name in con:
			if code in con[name][2]:
				if score > con[name][2][code]:
					con[name][0] += score-con[name][2][code]
					con[name][2][code] = score
					if score > 0:
						con[name][1] = (n-x)
			else:
				con[name][0] += score
				con[name][2][code] = score
				if score > 0:
					con[name][1] = (n-x)
		else:
			con[name] = [score, (n-x), {code:score}]
	conA = []
	for x in con:
		conA.append([x, con[x][0], con[x][1]])
	conA = sorted(conA, key = lambda x: x[1]*10000+x[2])
	print len(conA)
	for x in conA[::-1]:
		print x[0], x[1]