def solution(n, m, section):
    painted = section[0]
    cnt = 1
    for part in section:
        if part > painted + m - 1:
            painted = part
            cnt+= 1
    return cnt