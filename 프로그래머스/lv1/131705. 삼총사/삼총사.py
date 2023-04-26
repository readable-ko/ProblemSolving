from itertools import combinations

def solution(num):
    answer = 0
    for i in combinations(num, 3):
        if sum(i) == 0: answer += 1
    return answer