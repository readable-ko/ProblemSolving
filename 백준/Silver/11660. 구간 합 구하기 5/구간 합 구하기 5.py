import sys
N, M = map(int,sys.stdin.readline().split())
arr = [[0 for _ in range(N+1)]]
table = [[0 for _ in range(N+1)] for _ in range(N+1)]

for i in range(N):
    arr.append([0]+list(map(int, sys.stdin.readline().split())))

for row in range(1,N+1):
    rowSum = 0
    for col in range(N+1):
        rowSum += arr[row][col]
        table[row][col] = rowSum + table[row - 1][col]

for i in range(M):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    print(table[x2][y2] - table[x1-1][y2] - table[x2][y1-1] + table[x1-1][y1-1])