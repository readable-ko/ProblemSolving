import sys
MAX_ITERATE = 1000000

want = int(sys.stdin.readline())
brokenCnt = int(sys.stdin.readline())
brokenNum = []
answer = abs(100 - want)

if brokenCnt:
    brokenNum = list(map(int,sys.stdin.readline().split()))

def isPossible(num):
    for part in str(num):
        if int(part) in brokenNum:
            return False
    
    return True

for num in range(MAX_ITERATE):
    if isPossible(num):
        answer = min(answer, len(str(num)) + abs(num - want))

print(answer)