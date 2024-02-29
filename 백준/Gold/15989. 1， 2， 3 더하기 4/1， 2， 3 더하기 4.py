import sys
N = int(sys.stdin.readline().rstrip())
num = [int(sys.stdin.readline()) for _ in range(N)]
step = [[1,0,0] for _ in range(10001)]
step[2], step[3] = [1,1,0], [1,1,1]

for idx in range(4, 10001):
    step[idx][1] += sum(step[idx-2][:2])
    step[idx][2] += sum(step[idx-3])

for n in num:
    print(sum(step[n]))