import math

t = int(input())

for z in range(t):

	n, b = map(float, raw_input().split())

	if b >= n:

		print 0

	else:

		if n/2 < b:
			
			print int(n%b)	

		else:

			if (n/2)%b >= b/2:

				print int(((n/2)*(n/2)-(b-(n/2)%b)*(b-(n/2)%b))/b)

			else:

				print int(((n/2)*(n/2)-((n/2)%b)*((n/2)%b))/b)