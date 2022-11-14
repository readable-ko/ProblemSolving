def recursive(num):
    if(num == 0): return 1
    return num * recursive(num-1)

N = int(input())
print(recursive(N))