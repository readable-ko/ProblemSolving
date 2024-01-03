import sys
N = int(sys.stdin.readline())
dp = [0 for x in range(12)]
dp[1] = 1 # 1
dp[2] = 2 # 1+1 2
dp[3] = 4 # 1+1+1 1+2 2+1 3

for idx in range(4, 12):
    dp[idx] = dp[idx - 3] + dp[idx - 2] + dp[idx - 1]

for idx in range(N):
    num = int(sys.stdin.readline())
    print(dp[num])