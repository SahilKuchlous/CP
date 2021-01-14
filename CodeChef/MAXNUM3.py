t = int(input())

def compare (x, y, n):
	i = x
	while i < y:
		if n[i] < n[i+1]:
			return x
		elif n[i] > n[i+1]:
			return y
		i += 1
	return x

for z in range(t):
	n = raw_input()
	if len(n) == 1:
		print 0
	else:
		ans = []
		s = sum(map(int, list(n)))
		for x in range(len(n)):
			b = n[x]
			if x != len(n)-1:
				if (int(n[-1])%10)%2==0 and (s-int(b))%3 == 0:
					ans.append(x)
			else:
				if (int(n[-2])%10)%2==0 and (s-int(b))%3 == 0:
					ans.append(x)
		if len(ans) > 1:
			maxi = compare(ans[0], ans[1], n)
			for x in range(2, len(ans)):
				maxi = compare(maxi, x, n)
			print n[:maxi]+n[maxi+1:]
		elif len(ans) == 1:
			print n[:ans[0]]+n[ans[0]+1:]
		else:
			print -1