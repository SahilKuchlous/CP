t = int(input())

for e in range(t):
	
	l = int(input())
	colors = map(int, raw_input().strip().split(" "))

	curColor = colors[0]
	repititions = -1
	ans = 'No'
	for x in range(l):
		if colors[x] == curColor:
			repititions += 1
			if repititions >= 2:
				ans = 'Yes'
				break
		else:
			curColor = colors[x]
			repititions = 0

	print(ans)