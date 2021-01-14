import math
import fileinput
try:
	while 1:
		x = int(input())
		y = math.floor(x/2)+math.floor(x/3)+math.floor(x/4)
		print int(max(x, y))
except EOFError:
	exit()