def solution(foods):
    answer = ''
    
    for idx, food in enumerate(foods[-1::-1]):
        answer += str(len(foods) - idx - 1) * (food // 2)
    
    answer = answer[-1::-1] + '0' + answer
    return answer