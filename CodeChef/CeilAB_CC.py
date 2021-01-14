input = map(int, raw_input().strip().split(" "))
n1 = input[0]
n2 = input[1]
corAns = n1-n2
corAns = str(corAns)
corAns = ' '.join(corAns)
corAns = corAns.split(' ')
digit1 = corAns[0]
corAns.pop(0)
if digit1 == '9':
	digit1 = 8
else:
	digit1 = 9
corAns.insert(0, digit1)
corAns = map(str, corAns)
ans = ''.join(corAns)
print(ans)