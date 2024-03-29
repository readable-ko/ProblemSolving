import sys
from collections import deque

subin, sister = map(int, sys.stdin.readline().split())
visited = [0x3f3f3f3f for i in range(100001)]
visited[subin] = 0
cnt = 1 if subin == sister else 0

def check(depth, idx):
    if 0 <= idx <= 100000 and visited[depth] + 1 <= visited[idx]:
        visited[idx] = visited[depth] + 1
        return True
    return False

q = deque()
q.append(subin)

while len(q) > 0:
    front = q.popleft()

    for item in [front - 1, front + 1, front * 2]:
        if check(front, item):
            if item == sister:
                cnt += 1
            q.append(item)

print(visited[sister])
print(cnt)