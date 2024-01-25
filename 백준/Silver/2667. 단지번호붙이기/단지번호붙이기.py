import sys
N = int(sys.stdin.readline())
apart, answer = [], []
visited = [[False for _ in range(N)] for _ in range(N)]
dx, dy = [1,0,-1,0],[0,1,0,-1]

for i in range(N):
    apart.append(list(map(int,sys.stdin.readline()[:-1])))

def findBlock(r, c):
    global answer
    sub_ans = 1
    visited[r][c] = 1
    que = [[r,c]]
    
    while len(que):
        front = que.pop(0)
        
        for x, y in zip(dx, dy):
            nx, ny = front[0]+x, front[1]+y
            if 0 <= nx < N and 0 <= ny < N:
                if not visited[nx][ny] and apart[nx][ny]:
                    visited[nx][ny] = 1
                    sub_ans += 1
                    que.append([nx,ny])
    
    answer.append(sub_ans)

for i in range(N):
    for j in range(N):
        if not visited[i][j] and apart[i][j]:
            visited[i][j] = 1
            findBlock(i,j)

answer = sorted(answer)
print(len(answer))
for num in answer:
    print(num)