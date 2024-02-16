# dp[2] =                         3 * dp[0] + 2
# dp[4] =             3 * dp[2] + 2 * dp[0] + 2
# dp[6] = 3 * dp[4] + 2 * dp[2] + 2 * dp[0] + 2
# dp[6] - dp[4] = 3 * dp[4] - dp[2]
# dp[6] = 4 * dp[4] - dp[2]
def solution(n):
    answer = 0
    MOD = 1000000007
    dp = [0 for _ in range(n+1)]
    dp[2] = 3
    dp[4] = 11
    for val in range(6, n+1, 2):
        dp[val] = (dp[val - 2] * 4 - dp[val - 4]) % MOD
    return dp[n]