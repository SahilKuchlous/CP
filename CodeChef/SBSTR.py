'''
t = int(input())
for z in range(t):
	good = 0
	a = []
	s, k = raw_input().split()
	k = int(k)
	n = len(s)
	for x in range(n-k+1):
		for y in range(x+k, n+1):
			ss = s[x:y]
			d = {}
			for i in ss:
				if i in d:
					d[i] += 1
				else:
					d[i] = 1
			e = d[ss[0]]
			flag = True
			for i in d:
				if d[i] != e:
					flag = False
			if len(d) < k:
				flag = False
			if flag:
				good += 1
				a.append(ss)
	print good
	print a
'''

t = int(input())
for z in range(t):
	s, k = raw_input().split()
	k = int(k)
	n = len(s)
	a = []
	c = 0
	for x in range(n+1):
		b = []
		for y in range(26):
			b.append(0)
		a.append(b)
	for x in range(n):
		i = ord(s[x]) - ord('a')
		if x == 0:
			a[x+1][i] = 1
		else:
			a[x+1] = a[x][:]
			a[x+1][i] += 1
	for x in range(n-k+1):
		for y in range(x+k, n+1):
			b = []
			for i in range(26):
				b.append(0)
			for i in range(26):
				b[i] = a[y][i] - a[x][i]
			d = [i for i in b if i != 0]
			if len(d) >= k and len(set(d)) <= 1:
				c += 1
	print c