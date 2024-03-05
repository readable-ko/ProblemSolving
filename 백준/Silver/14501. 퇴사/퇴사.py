import sys
N = int(sys.stdin.readline())
table = [0 for _ in range(N+1)]
for idx in range(N):
    
    time, price = map(int,sys.stdin.readline().split())
    table[idx] = max(table[idx], table[idx - 1])
    
    if idx + time > N:
        continue
    table[idx + time] = max(table[idx + time], table[idx] + price)

print(max(table[-1],table[-2]))