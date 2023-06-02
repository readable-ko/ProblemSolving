def solution(n, l, r):
    answer = 0

    for l in range(l-1, r):
        if check(l):
            answer += 1

    return answer

def check(i):
    if i % 5 == 2:
        return False
    if i < 5:
        return True


    return check(i // 5)
#11011 5^1 4^1
#11011 11011 00000 11011 11011 5^2 4^2
#11011 11011 00000 11011 11011 4번 00000 00000 00000 00000 00000 5^3 4^3