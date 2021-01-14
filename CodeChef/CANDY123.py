t = int(input())

for x in range(t):
	a, b = map(int, raw_input().split())
	ac = 0
	at = 0
	aa = 1
	while ac + aa <= a:
		ac += aa
		at += 1
		aa += 2

	bc = 0
	bt = 0
	ba = 2
	while bc + ba <= b:
		bc += ba
		bt += 1
		ba += 2

	if at > bt:
		print 'Limak'
	else:
		print 'Bob'