def solution(targets):
    answer, missile = 0, 0
    targets = sorted(targets, key = lambda x : x[1])

    for target in targets:
        sp, ep = target
        if sp >= missile:
            missile = ep
            answer += 1
    return answer