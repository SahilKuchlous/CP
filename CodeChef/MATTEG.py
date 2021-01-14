t = int(input())
maxsum = 0

def move(x, y, px, py, sum, g, r, c, n, no):

	global maxsum
	# print '  '*(no-n) + `x`, `y`, sum

	if sum > maxsum:
		maxsum = sum
	
	for i in range(n):
		
		nx = x + px[i]
		ny = y + py[i]
		if nx < c and ny < r:
			move(nx, ny, px[:i]+px[i+1:], py[:i]+py[i+1:], sum + g[ny][nx], g, r, c, n-1, no)

		nx = x + px[i]
		ny = y - py[i]
		if nx < c and ny > -1:
			move(nx, ny, px[:i]+px[i+1:], py[:i]+py[i+1:], sum + g[ny][nx], g, r, c, n-1, no)

		nx = x - px[i]
		ny = y + py[i]
		if nx > -1 and ny < r:
			move(nx, ny, px[:i]+px[i+1:], py[:i]+py[i+1:], sum + g[ny][nx], g, r, c, n-1, no)

		nx = x - px[i]
		ny = y - py[i]
		if nx > -1 and ny > -1:
			move(nx, ny, px[:i]+px[i+1:], py[:i]+py[i+1:], sum + g[ny][nx], g, r, c, n-1, no)


for z in range(t):
	
	r, c, n = map(int, raw_input().split())
	sx, sy = map(int, raw_input().split())
	px = map(int, raw_input().split())
	py = map(int, raw_input().split())
	g = []
	for x in range(r):
		g.append(map(int, raw_input().split()))
	maxsum = 0
	move(sx, sy, px, py, g[sy][sx], g, r, c, n, n)
	print maxsum