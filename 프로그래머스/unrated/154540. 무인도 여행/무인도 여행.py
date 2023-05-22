import sys
sys.setrecursionlimit(10**5)

def DFS(c, r, cnt, maps, check):

    dx, dy = [1,0,-1,0], [0,1,0,-1]

    for i, j in zip(dx, dy):
        nx, ny = c + i, r + j
        if (0 <= nx < len(maps)) and (0 <= ny < len(maps[0])):
            if maps[nx][ny] != 'X' and check[nx][ny] == False:
                check[nx][ny] = True
                cnt = DFS(nx, ny, int(maps[nx][ny]) + cnt, maps, check)

    return cnt

def solution(maps):
    answer = []
    MAX_COL = len(maps)
    MAX_ROW = len(maps[0])
    check = [[False] * MAX_ROW for _ in range(MAX_COL)]

    for c in range(MAX_COL):
        for r in range(MAX_ROW):
            if maps[c][r] != 'X' and check[c][r] == False:
                check[c][r] = True
                answer.append(DFS(c, r, int(maps[c][r]), maps, check))
    
    if len(answer) == 0:
        answer .append(-1)
    return sorted(answer)