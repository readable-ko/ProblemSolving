from collections import Counter

def solution(X, Y):
    answer = ''
    list_x = Counter(X)#[X.count(str(x)) for x in range(10)]
    list_y = Counter(Y)#[Y.count(str(y)) for y in range(10)]
    
    for i in range(9, -1, -1):
        i = str(i)
        answer += i * min(list_x[i], list_y[i])
    
    if len(answer) == 0:
        answer = '-1'
    elif answer[0] == '0':
        answer = '0'
        
    return answer