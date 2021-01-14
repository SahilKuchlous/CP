n, m, k = map(int, raw_input().split())

switches = []
for a in range(m):
	x, y = map(int, raw_input().split())
	switches.append((x, y))

s1 = filter(lambda x: x[0] == 0 and x[1] != 0, switches)
s1 = sorted(s1, key = lambda x: x[1])
s2 = filter(lambda x: x[1] == n and x[0] != 0, switches)
s2 = sorted(s2, key = lambda x: x[0])
s3 = filter(lambda x: x[0] == n and x[0] != 5, switches)
s3 = sorted(s3, key = lambda x: x[1], reverse = True)
s4 = filter(lambda x: x[1] == 0 and x[1] != 5, switches)
s4 = sorted(s4, key = lambda x: x[0], reverse = True)
switches = s1+s2+s3+s4

ld = 100000000
d = 0
s = switches[:k]
for x in range(k-1):
	d += abs(s[x][0]-s[x+1][0]) + abs(s[x][1]-s[x+1][1])
ld = d
switches += switches
for a in range(m):
	d -= abs(switches[a][0]-switches[a+1][0]) + abs(switches[a][1]-switches[a+1][1])
	d += abs(switches[a+k-1][0]-switches[a+k][0]) + abs(switches[a+k-1][1]-switches[a+k][1])
	if d < ld:
		ld = d
print ld