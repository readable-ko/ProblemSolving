import sys
from itertools import combinations

N, M = map(int,sys.stdin.readline().split())
area, chicken, house, distance = [], [], [], []

for i in range(N):
    area.append(list(map(int,sys.stdin.readline().split())))
    for j in range(N):
        if area[i][j] == 2:
            chicken.append([i,j])
        elif area[i][j] == 1:
            house.append([i,j])

distance = [[] for _ in range(len(chicken))]

for idx in range(len(chicken)):
    x, y = chicken[idx]
    for h in house:
        r, c = h
        distance[idx].append(abs(x - r) + abs(y - c))

answer = sum(distance[0])
for choosen in combinations(distance, M):
    subAnswer = choosen[0].copy()
    
    for d in choosen:
        for idx in range(len(d)):
            subAnswer[idx] = min(subAnswer[idx], d[idx])
    answer = min(answer, sum(subAnswer))

print(answer)