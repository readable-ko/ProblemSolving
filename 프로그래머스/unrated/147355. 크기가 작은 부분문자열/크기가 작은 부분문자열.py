def solution(t, p):
    answer = 0
    size = len(p)
    for i in range(len(t) - size + 1):
        target = int(t[i:i+size])
        point = int(p)

        if target <= point:
           answer += 1
    return answer