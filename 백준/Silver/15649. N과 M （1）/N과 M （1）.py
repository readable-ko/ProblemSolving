import sys
N, M = map(int,sys.stdin.readline().split())

def permutation(l:list=[], depth = 0):
    if depth == M:
        print(*l)
        return
    
    for num in range(1, N+1):
        if num in l:
            continue
        l.append(num)
        permutation(l, depth + 1)
        l.pop()
    return

permutation()