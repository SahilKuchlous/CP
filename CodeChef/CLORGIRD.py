t = int(input())
for i in range(t):
	n, m = map(int, raw_input().split())
	a = []
	a.append(['#']*(m+2))
	for x in range(n):
		a.append(['#']+list(raw_input())+['#'])
	a.append(['#']*(m+2))
	
	o = True
	for x in range(1, n+1):
		for y in range(1, m+1):
			if a[x][y] == '.':
				r = True if a[x][y+1] == '.' else False
				l = True if a[x][y-1] == '.' else False
				u = True if a[x-1][y] == '.' else False
				d = True if a[x+1][y] == '.' else False
				ur = True if a[x-1][y+1] == '.' else False
				ul = True if a[x-1][y-1] == '.' else False
				dr = True if a[x+1][y+1] == '.' else False
				dl = True if a[x+1][y-1] == '.' else False
				if (r and ur and u) or (r and dr and d) or (l and ul and u) or (l and dl and d):
					continue
				else:
					o = False
					break
	
	if o:
		print 'YES'
	else:
		print 'NO'