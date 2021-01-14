t = int(input())
for z in range(t):
	n, m = map(int, raw_input().split())
	g = []
	for x in range(n):
		g.append(map(int, list(raw_input())))
	s = list(raw_input())
	for c in s:
		if c == 'L':
			for x in range(n):
				for y in range(m):
					if g[x][y] == 1:
						yc = y
						while yc > 0 and g[x][yc-1] == 0:
							g[x][yc] = 0
							yc -= 1
							g[x][yc] = 1
		if c == 'R':
			for x in range(n):
				for y in range(m-1, -1, -1):
					if g[x][y] == 1:
						yc = y
						while yc < m-1 and g[x][yc+1] == 0:
							g[x][yc] = 0
							yc += 1
							g[x][yc] = 1
		if c == 'U':
			for x in range(n):
				for y in range(m):
					if g[x][y] == 1:
						xc = x
						while xc > 0 and g[xc-1][y] == 0:
							g[xc][y] = 0
							xc -= 1
							g[xc][y] = 1
		if c == 'D':
			for x in range(n-1, -1, -1):
				for y in range(m):
					if g[x][y] == 1:
						xc = x
						while xc < n-1 and g[xc+1][y] == 0:
							g[xc][y] = 0
							xc += 1
							g[xc][y] = 1
	for x in g:
		print ''.join(map(str, x))
