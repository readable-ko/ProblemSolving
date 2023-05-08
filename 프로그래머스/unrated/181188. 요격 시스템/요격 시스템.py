def solution(targets):
    answer = 1
    targets = sorted(targets, key=lambda x: x[1])
    curr = targets[0][1]
    
    for t in targets:
        if t[0] >= curr:
            answer+= 1
            curr = t[1]

    return answer