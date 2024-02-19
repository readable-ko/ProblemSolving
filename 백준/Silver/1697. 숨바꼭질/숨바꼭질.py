import sys
N, K = map(int,sys.stdin.readline().split())
position = [abs(N - val) for val in range(100001)]

for idx in range(N+1, K+1):
    if idx & 1:
        position[idx] = min(position[(idx - 1) // 2] + 2, position[(idx + 1) // 2] + 2, position[idx - 1] + 1)
    else:
        position[idx] = min(position[idx // 2] + 1, position[idx - 1] + 1)

print(position[K])