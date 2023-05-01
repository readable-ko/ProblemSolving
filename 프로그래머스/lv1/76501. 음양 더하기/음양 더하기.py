def solution(absolutes, signs):
    sign = {1: 1, 0: -1}        
    return sum(sign[signs[idx]] * num for idx, num in enumerate(absolutes))