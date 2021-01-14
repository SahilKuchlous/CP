import math

def connected(current, visited, n, coprimes):
	visited.add(current)
	if len(visited) == n:
		return True
	for x in coprimes[current]:
		if x not in visited:
			a = connected(x, visited, n, coprimes)
			if a:
				return True

t = int(input())
for z in range(t):
	
	n = int(input())
	a = list(map(int, input().split(' ')))
	coprimes = []
	for x in range(n):
		coprimes.append(set())
	for x in range(n):
		for y in range(x+1, n):
			if math.gcd(a[x], a[y]) == 1:
				coprimes[x].add(y)
				coprimes[y].add(x)
	o = connected(0, set(), n, coprimes)
	if o:
		print(0)
		print(' '.join(map(str, a)))
	else:
		print(1)
		print((str(31) if len([x for x in a if x != 31])>0 else str(37)) + ' ' + ' '.join(map(str, a[1:])))