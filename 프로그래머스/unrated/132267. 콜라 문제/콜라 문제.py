def solution(a, b, n):
    answer = 0
    cnt = 1
    while n >= a:
        given = n // a
        answer += given * b
        n = n - (a*given) + (given * b)
    return answer