n = int(input())
grid = []
memo = []
for x in range(n):
	grid.append(list(map(int, input().split())))
	mr = []
	for y in range(n):
		mr.append(-1)
	memo.append(mr)
memo[n-1][n-1] = 1
def rec (x, y):
	if x >= n or y >= n: return 0
	if memo[x][y] != -1: return memo[x][y]
	if grid[x][y] == 0: return 0
	memo[x][y] = rec(x+grid[x][y], y)+rec(x, y+grid[x][y])
	return memo[x][y]
print(rec(0, 0))