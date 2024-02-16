import sys
N = int(sys.stdin.readline())

def hanoi(N, sp, ep, tmp):
    if N == 1:
        print(sp, ep)
        return
    
    hanoi(N-1, sp, tmp, ep)
    print(sp, ep)
    hanoi(N-1, tmp, ep, sp)

print(2**N - 1)
hanoi(N, 1, 3, 2)