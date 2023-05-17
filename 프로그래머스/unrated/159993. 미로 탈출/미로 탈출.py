def BFS(sx, sy, x, y, maps):
    check = list([0] * len(maps[i]) for i in range(len(maps)))
    que = [[sx,sy]]
    dx = [0,1,0,-1]
    dy = [1,0,-1,0]
    flag = False
    
    while len(que):
        pos = que[0]
        que.pop(0)
        if pos == [x, y]:
            flag = True
            break
        
        for i,j in zip(dx, dy):
            nx = pos[0] + i
            ny = pos[1] + j
            if 0 <= nx < len(maps) and 0 <= ny < len(maps[0]):
                if maps[nx][ny] != 'X' and check[nx][ny] == 0:
                    check[nx][ny] = check[pos[0]][pos[1]] + 1
                    que.append([nx, ny])
                    
    return check[x][y] if flag else -1

def solution(maps):
    answer = 0
    start = []
    lever = []
    exit_ = []
    for i in range(len(maps)):
        if 'S' in maps[i]:
            start.append(i)
            start.append(maps[i].index('S'))
        if 'E' in maps[i]:
            exit_.append(i)
            exit_.append(maps[i].index('E'))
        if 'L' in maps[i]:
            lever.append(i)
            lever.append(maps[i].index('L'))
    
    #print(start)
    to_lev = BFS(start[0], start[1], lever[0], lever[1], maps)
    to_exi = BFS(lever[0], lever[1], exit_[0], exit_[1], maps)

    return -1 if(to_lev == -1 or to_exi == -1) else to_lev + to_exi