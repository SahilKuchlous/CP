import math

nc, nv, nw = map(int, raw_input().split())
c = [None]*nc
for x in range(nc):
	s, e = map(int, raw_input().split())
	c[x] = (s, e)
v = map(int, raw_input().split())
w = map(int, raw_input().split())

c = [[i, c[i]] for i in range(nc)]
cv = sorted(c, key = lambda x: x[1][0])
cw = sorted(c, key = lambda x: x[1][1], reverse = True)
v = sorted(v)
w = sorted(w, reverse = True)
vc = [-1000000]*nc
wc = [1000000]*nc

iv = 0
for x in xrange(nc):
	if cv[x][1][0] >= v[0]:
		for y in xrange(iv, nv):
			if cv[x][1][0] >= v[y]:
				iv = y
				vc[cv[x][0]] = v[y]
			else:
				break

iw = 0
for x in xrange(nc):
	if cw[x][1][1] <= w[0]:
		for y in xrange(iw, nw):
			if cw[x][1][1] <= w[y]:
				iw = y
				wc[cw[x][0]] = w[y]
			else:	
				break

'''
v = sorted(v) + [1000000]
w = sorted(w, reverse = True) + [-1000000]
vc = [-1000000]*nc
wc = [1000000]*nc

for x in range(nc):
	high = nv-1
	low = 0
	mid = (high+low)/2
	while high >= low:
		mid = (high+low)/2
		if v[mid] > c[x][0]:
			high = mid-1
		elif v[mid+1] <= c[x][0]:
			low = mid+1
		else:
			vc[x] = v[mid]
			break

for x in range(nc):
	high = nw-1
	low = 0
	mid = (high+low)/2
	while high >= low:
		mid = (high+low)/2
		if w[mid+1] >= c[x][1]:
			low = mid+1
		elif w[mid] < c[x][1]:
			high = mid-1
		else:
			wc[x] = w[mid]
			break
'''

print min([(wc[i] - vc[i] + 1) for i in range(nc)])
