t = int(input())

def findNeigbours(g, x, y, n, m):
	neighbours = []
	if x < m-1:
		neighbours.append(g[y][x+1])
	if x > 0:
		neighbours.append(g[y][x-1])
	if y < n-1:
		neighbours.append(g[y+1][x])
	if y > 0:
		neighbours.append(g[y-1][x])
	return neighbours

for z in range(t):
	c = 0
	n, m = map(int, raw_input().split())
	g = []
	for x in range(n):
		g.append(map(int, raw_input().split()))
	while len(set([item for sublist in g for item in sublist])) != 1:
		gd = [x[:] for x in g]
		for y in range(n):
			for x in range(m):
				neighbours = findNeigbours(g, x, y, n, m)
				print x, y, neighbours
				gd[y][x] = max(neighbours)
		g = [x[:] for x in gd]
		c += 1
	print c

