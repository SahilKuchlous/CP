t = int(input())

def checkSnake(r, c, platei, n):
	plate = []
	for x in platei:
		plate.append(x[:])
	while True:
		plate[r][c] = '.'
		if plate[(r+1)%2][c] == '#':
			r = (r+1)%2
		elif c == n-1:
			break
		elif plate[r][c+1] == '#':
			c = c+1
		else:
			break
	for row in plate:
		if row.count('#') != 0:
			return False
	return True

for z in range(t):

	n = int(input())
	r1 = list(raw_input())
	r2 = list(raw_input())
	plate = [r1, r2]

	if ('#' in plate[0] and checkSnake(0, plate[0].index('#'), plate, n)) or ('#' in plate[1] and checkSnake(1, plate[1].index('#'), plate, n)):
		print 'yes'
	else:
		print 'no'