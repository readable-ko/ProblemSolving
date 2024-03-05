import sys

N, maximum = int(sys.stdin.readline()), 0
arr, dp = [[0,0]], [0] * (N+2)
TIME, PRICE = 0, 1

for i in range(1, N+1):
    arr.append(list(map(int,sys.stdin.readline().split())))

for i in range(N, 0, -1):
    if i + arr[i][TIME] <= N + 1:
        dp[i] = dp[i + arr[i][TIME]] + arr[i][PRICE]
    dp[i] = max(dp[i], dp[i+1])

print(max(dp))