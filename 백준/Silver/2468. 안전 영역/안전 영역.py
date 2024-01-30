import sys
sys.setrecursionlimit(10**5)
N = int(sys.stdin.readline())
maxHeight, answer = 0, 0
dx, dy = [1,0,-1,0], [0,1,0,-1]
area = []
visited = []

def findArea(flood, r, c):
    global visited
    
    for x, y in zip(dx, dy):
        R, C = r + x, c + y
        if 0 <= R < N and 0 <= C < N:
            if not visited[R][C] and area[R][C] > flood:
                visited[R][C] = True
                findArea(flood, R, C)
                
    return

for idx in range(N):
    area.append(list(map(int,sys.stdin.readline().split())))
    maxHeight = max(maxHeight, max(area[idx]))

for flood in range(maxHeight+1):
    visited = [[False for _ in range(N)] for _ in range(N)]
    cnt = 0
    for row in range(N):
        for col in range(N):
            if not visited[row][col] and area[row][col] > flood:
                findArea(flood, row, col)
                cnt += 1
    
    answer = max(answer, cnt)

print(answer)