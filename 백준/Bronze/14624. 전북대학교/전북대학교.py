N = int(input())
half = N//2
if N & 1 == 0:
    print('I LOVE CBNU')
else:
    for i in range(N):
        print('*', end="")
    print()
    
    for i in range(N - half):
        for j in range(0, N):
            if j == half + i:  print('*', end="")
            elif j == half - i: print("*", end="")
            elif j > half + i: break
            else:  print(' ', end="")
        print()