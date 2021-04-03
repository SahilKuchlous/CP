t = int(input())
for z in range(t):
    l = int(input())
    s = raw_input()
    o = ''
    for x in s:
        if x == 'S':
            o += 'E'
        else:
            o += 'S'
    print 'Case #' + str(z+1) + ': ' + str(o)