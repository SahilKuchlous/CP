str = raw_input()

num = 0
largestNum = 0
largestS = 0
largestE = 0
for x in range (len(str)):
	if str[x] == '(':
		num += 1
		if num > largestNum:
			largestNum = num
			largestS = x
	if str[x] == ')':
		num -= 1
		if num + 1 == largestNum:
			largestE = x

output = str[int(largestS) + 1:int(largestE)]
print(output)

