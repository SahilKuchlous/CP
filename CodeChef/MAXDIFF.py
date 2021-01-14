t = int(input())
for z in range(t):
	n, k = map(int, raw_input().split())
	w = map(int, raw_input().split())
	w = sorted(w)
	if sum(w[k:])-sum(w[:k]) > sum(w[(n-k):])-sum(w[:(n-k)]):
		print sum(w[k:])-sum(w[:k])
	else:
		print sum(w[(n-k):])-sum(w[:(n-k)])