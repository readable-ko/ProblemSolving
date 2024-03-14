import sys
from collections import deque
N, M = map(int, sys.stdin.readline().split())
student = [[] for _ in range(N+1)]
order = [0 for _ in range(N+1)]
answer = []

def find():
    q = deque()
    for i in range(1,N+1):
        if order[i] == 0:
            q.append(i)
            answer.append(i)

    while len(q):
        i = q.popleft()

        for s in student[i]:
            order[s] -= 1
            if order[s] == 0:
                q.append(s)
                answer.append(s)

    return


for _ in range(M):
    a, b = map(int, sys.stdin.readline().split())
    student[a].append(b)
    order[b] += 1

find()
print(*answer)