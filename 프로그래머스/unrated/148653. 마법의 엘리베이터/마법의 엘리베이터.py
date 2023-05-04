def solution(storey):
    if storey < 10:
        return min(storey, 11 - storey)
    else:
        now = storey % 10
        return min(now + solution(storey // 10), (10 - now) + solution(storey // 10 + 1))