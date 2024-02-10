import sys
from collections import defaultdict

# 조건 1. 로봇은 올리는 위치에서만 올리 수 있고 내리는 위치 도착 즉시 내려짐

# 1. 벨트가 로봇과 함께 회전
# 2. 가장 먼저 올라간 로봇부터 벨트 회전 방향으로 1칸 이동
# 2-1. 이동하려는 칸에 내구도가 1이상, 로봇 없어야함
# 3. 올리는 위치 내구도 0 아니면 로봇 올림
# 4. 내구도가 0인 칸의 개수가 K 이상이면 종료

"""
구현
cnt가 K가 되면 반복문 종료시킴
벡터 뒤에 계속 추가하는 형식으로 진행
뒤에서부터 훝어보며 코드를 작성
"""
N, K = map(int, sys.stdin.readline().split())
values = list(map(int, sys.stdin.readline().split()))
belt = []
for idx in range(2 * N - 1, -1, -1):
    belt.append([values[idx], 0])
cnt, step, sp = 0, 0, 0


def isEmptySpace(idx):
    return belt[idx - 1][1] == 0


def isRobotExist(idx):
    return belt[idx][1] == 1


def hasEnergy(idx):
    return belt[idx][0] != 0


def rotateBelt():
    global sp
    belt.append(belt[sp])
    sp += 1
    belt[sp + N][1] = 0


def moveRobot():
    global cnt
    for idx in range(sp + 1, len(belt)):
        if cnt == K:
            break
        if isEmptySpace(idx) and isRobotExist(idx) and hasEnergy(idx - 1):
            belt[idx - 1][1] = 1
            belt[idx][1] = 0
            belt[idx - 1][0] -= 1
            belt[sp + N][1] = 0

            if not hasEnergy(idx - 1):
                cnt += 1


def insertRobot():
    global cnt
    if hasEnergy(-1) and isEmptySpace(0):
        belt[-1][0] -= 1
        belt[-1][1] = 1
        if not hasEnergy(-1):
            cnt += 1


def simulate():
    rotateBelt()
    moveRobot()
    insertRobot()
    return


while cnt < K:
    simulate()
    step += 1
print(step)