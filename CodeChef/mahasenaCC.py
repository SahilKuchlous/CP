no_s = int(input())
weapons = raw_input().strip().split(" ")
luck = 0
for x in weapons:
	x = int(x)
	if x%2 == 0:
		luck += 1
	elif x%2 == 1:
		luck -= 1
print(luck)
if luck > 0:
	print('READY FOR BATTLE')
else:
	print('NOT READY')