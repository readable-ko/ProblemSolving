import sys
N = int(sys.stdin.readline())
ONE = 0
TWO = 1

stair = [0]
save = [[0, 0] for i in range(N + 1)]

for i in range(N):
    stair.append(int(sys.stdin.readline()))

save[1][ONE] = stair[1]
save[1][TWO] = stair[1]

for i in range(2, N+1):
    save[i][TWO] = save[i-1][ONE] + stair[i];
    save[i][ONE] = max(save[i-2][ONE], save[i-2][TWO]) + stair[i];

print(max(save[N]))