import sys
N, R, C = map(int,sys.stdin.readline().split())
N = 2 ** N
answer = 0

def find(sz, row, col):
    global answer
    n = sz // 2
    
    if sz == 1:
        return
    
    if row < n:
        if col < n:
            find(n, row, col)
        else:
            answer += n ** 2
            find(n, row, col - n)
    else:
        if col < n:
            answer += (n ** 2) * 2
            find(n, row - n, col)
        else:
            answer += (n ** 2) * 3
            find(n, row - n, col - n)

    return

find(N, R, C)

print(answer)