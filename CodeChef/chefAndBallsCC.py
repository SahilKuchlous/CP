import sys

print('1')
sys.stdout.flush()
print('4 1 1 2 3')
sys.stdout.flush()
print('4 3 4 5 5')
sys.stdout.flush()
output = int(input())

if output == 2:
	color = 1
elif output == 1:
	color = 2
elif output == 0:
	color = 3
elif output == -1:
	color = 4
elif output == -2:
	color = 5

print('2')
sys.stdout.flush()
print(color)
sys.stdout.flush()


