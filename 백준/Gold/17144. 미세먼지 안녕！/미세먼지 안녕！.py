from collections import deque

class Dust:
    x_ = 0
    y_ = 0
    n_ = 0
    def __init__(self, x, y, n=0):
        self.x_ = x
        self.y_ = y
        self.n_ = n

munzi = [[0] * 52 for i in range(52)]
x_way = [-1, 0, 1, 0]
y_way = [0, 1, 0, -1]
CLOCKWISE = -1
ANTICLOCK = 1
cw = [0, 1, 2, 3]
ccw = [2, 1, 0, 3]
machine = []

def Diffusion():
    q = deque()

    for i in range(1, r+1):
        for j in range(1, c+1):
            if munzi[i][j] > 0:
                q.append(Dust(i, j, (munzi[i][j])))

    while q:
        x = q[0].x_
        y = q[0].y_
        cnt = 0
        share = q[0].n_ // 5
        q.popleft()

        for i in range(4):
            new_x = x + x_way[i]
            new_y = y + y_way[i]

            if new_x < 1 or new_x > r or new_y < 1 or new_y > c:
                continue

            if munzi[new_x][new_y] != -1:
                cnt += 1
                munzi[new_x][new_y] += share

        munzi[x][y] -= cnt * share
    
    return

def Ventilation(row, col, wise, rot):
    x = row + wise
    y = col
    for way in range(4):
        while True:
            new_x = x + x_way[rot[way]]
            new_y = y + y_way[rot[way]]
            if wise == CLOCKWISE:
                if new_x < 1 or new_x > row or new_y < 1 or new_y > c:
                    break
            else:
                if new_x < row or new_x > r or new_y < 1 or new_y > c:
                    break
            if new_x == row and new_y == col:
                break

            munzi[x][y] = munzi[new_x][new_y]
            x = new_x
            y = new_y

    munzi[row][col + 1] = 0

answer = 0
r, c, times = map(int, input().split())

for i in range(1, r+1):
    row = list(map(int, input().split()))
    for j in range(1, c+1):
        munzi[i][j] = row[j-1]
        if munzi[i][j] == -1:
            machine.append(Dust(i, j))

for t in range(times):
    Diffusion()
    Ventilation(machine[0].x_, machine[0].y_, CLOCKWISE, cw)
    Ventilation(machine[1].x_, machine[1].y_, ANTICLOCK, ccw)

for i in range(1, r+1):
    for j in range(1, c+1):
        answer += munzi[i][j]

print(answer + 2)
