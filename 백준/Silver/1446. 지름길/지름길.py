import sys
route, distance = map(int, sys.stdin.readline().split())
shortPath = [list(map(int, sys.stdin.readline().split())) for _ in range(route)]

answer = [val for val in range(distance + 1)]

for d in range(distance + 1):
    if d > 0:
        answer[d] = min(answer[d], answer[d - 1] + 1)
    for sp, ep, dist in shortPath:
        if sp != d or ep > distance:
            continue
        answer[ep] = min(answer[ep], answer[d] + dist)

print(answer[-1])