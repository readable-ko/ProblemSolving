def solution(foods):
    answer = ''
    
    for idx, food in enumerate(foods):
        answer += str(idx) * (food // 2)
    
    answer = answer + '0' + answer[-1::-1]
    return answer