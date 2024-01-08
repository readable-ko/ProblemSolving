import sys
sp, ep = 1, 2**31
havingLine, wantLine = map(int,sys.stdin.readline().split())
lines = []

for i in range(havingLine):
    lines.append(int(sys.stdin.readline()))

def check(val):
    cnt = 0
    for line in lines:
        cnt += line // val
    
    if cnt >= wantLine:
        return True
    return False

while sp < ep:
    mid = (sp + ep + 1) // 2
    if check(mid):
        sp = mid
    else:
        ep = mid - 1

print(sp)