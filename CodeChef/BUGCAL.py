t = int(input())

for z in range(t):
	
	a, b = map(str,map(int,raw_input().split()))
	n = ''
	if len(a) > len(b):
		b = '0'*(len(a)-len(b))+b
	elif len(b) > len(a):
		a = '0'*(len(b)-len(a))+a
	for x in range(len(a)):
		n += str(int((int(a[x]) + int(b[x]))%10))
	print str(int(n))