import sys
INF = 0x3f3f3f3f
MAX_RANGE = 100001

N, K = map(int,sys.stdin.readline().split())
coinCount = [INF for x in range(MAX_RANGE)]
givenCoin = []

for i in range(N):
    coin = int(sys.stdin.readline())
    coinCount[coin] = 1
    givenCoin.append(coin)
givenCoin.sort()

for now in range(K+1):
    for coin in givenCoin:
        if now - coin > 0:
            coinCount[now] = min(coinCount[now], coinCount[now - coin] + 1)


print("-1" if coinCount[K] >= INF else coinCount[K])