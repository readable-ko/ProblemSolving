import sys
N = int(sys.stdin.readline())
if N == 1 or N == 3:
    print(-1)
else:
    answer = (N // 5)
    if (N % 5) % 2 != 0:
        answer -= 1
        answer += (N - (answer * 5)) // 2
    else:
        answer += (N - (answer * 5)) // 2
    print(answer)
