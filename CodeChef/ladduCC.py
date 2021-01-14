import math

t = int(input())

for e in range(t):
	
	l = raw_input().strip().split(" ")
	activities = l[0]
	origin = l[1]
	laddus = 0
	
	for x in range(int(activities)):
		act = raw_input().strip().split(" ")
		if len(act) > 1:
			if act[0] == 'CONTEST_WON':
				laddus += 300
				rank = int(act[1])
				if rank < 20:
					laddus += 20 - rank 
			elif act[0] == 'BUG_FOUND':
				severity = act[1]
				laddus += int(severity)
		elif len(act) == 1:
			if act[0] == 'TOP_CONTRIBUTOR':
				laddus += 300
			elif act[0] == 'CONTEST_HOSTED':
				laddus += 50

	months = 0
	if origin == 'INDIAN':
		months = math.floor(int(laddus)/200)
	elif origin == 'NON_INDIAN':
		months = math.floor(int(laddus)/400)

	print(int(months))

	laddus = 0