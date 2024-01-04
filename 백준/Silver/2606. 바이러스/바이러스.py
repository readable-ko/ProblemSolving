import sys

N = int(sys.stdin.readline())
connectLength = int(sys.stdin.readline())
computers = [[] for i in range(N+1)]
visited = [False for i in range(N+1)]
visited[1] = True

def findVirus(node):
    cnt = 0
    for computer in computers[node]:
        if not visited[computer]:
            visited[computer] = True
            cnt += findVirus(computer) + 1
    return cnt

for connect in range(connectLength):
    lhs, rhs = map(int, sys.stdin.readline().split())
    computers[lhs].append(rhs)
    computers[rhs].append(lhs)

print(findVirus(1))