import sys

t = int(input())

for a in range(t):
	coords = map(int, raw_input().split())
	commands = list(raw_input())
	x = 0
	y = 0
	mx = 0
	my = 0
	lx = 0
	ly = 0
	
	for c in commands:
		if c == 'L':
			x -= 1
		elif c == 'R':
			x += 1
		elif c == 'U':
			y -= 1
		elif c == 'D':
			y += 1
		if x > mx:
			mx = x
		if x < lx:
			lx = x
		if y > my:
			my = y
		if y < ly:
			ly = y
	
	if abs(lx) + abs(mx) < coords[1] and abs(ly) + abs(my) < coords[0]:
		print 'safe'
	else:
		print 'unsafe'
