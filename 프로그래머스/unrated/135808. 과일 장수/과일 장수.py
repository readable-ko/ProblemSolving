def solution(k, m, score):
    return sum(sorted(score, reverse=True)[m-1::m] * m)