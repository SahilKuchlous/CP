t = int(input())
 
for z in range(t):
	n = raw_input()
	if len(n) == 1:
		print 0
	else:
		ans = []
		s = sum(map(int, list(n)))
		for x in range(len(n)-1, -1, -1):
			b = n[x]
			a = n[:x]+n[x+1:]
			if (int(a[-1])%10)%2==0 and (s-int(b))%3 == 0:
				ans.append(a)
		if len(ans) > 0:
			print max(ans)
		else:
			print -1