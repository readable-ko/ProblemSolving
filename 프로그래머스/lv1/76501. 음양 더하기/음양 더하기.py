def solution(absolutes, signs):
    answer = 0
    sign = {1: 1, 0: -1}
    for idx, num in enumerate(absolutes):
        answer += sign[signs[idx]] * num
    return answer