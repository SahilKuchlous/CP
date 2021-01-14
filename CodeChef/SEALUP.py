import math
t = int(input())
for a in range(t):
	vc = int(input())
	t = []
	v = []
	for x in range(vc):
		v.append(map(int, raw_input().split()))
	tc = int(input())
	for x in range(tc):
		t.append(map(int, raw_input().split()))
	l = []
	for x in range(len(v)):
		v1 = v[x]
		v2 = v[(x+1)%vc]
		d = math.sqrt(math.pow(v1[0]-v2[0], 2) + math.pow(v1[1]-v2[1], 2))
		l.append(d)

	c = 0
	ch = max(t, key = lambda x: x[0]/x[1])
	for x in l:
	    c += math.floor(x/ch[0])*ch[1]
	    x %= ch[0]
	    m = math.ceil(x/t[0][0])*t[0][1]
	    for y in t:
		    if math.ceil(x/y[0])*y[1] < m:
		        m = math.ceil(x/y[0])*y[1]
	    c += m
	print int(c)