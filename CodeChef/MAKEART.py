t = int(input())
found = False
for i in range(t):
    l = int(input())
    c = list(map(int, input().split()))
    for j in range(len(c)-2):
        if c[j] == c[j+1] == c[j+2]:
            print('Yes')
            found = True
            break
    if found != True:
        print('No')
    found = False
