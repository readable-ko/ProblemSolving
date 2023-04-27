def solution(X, Y):
    answer = ''
    list_x = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    list_y = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]


    for x in X:
        list_x[int(x)] += 1
    for y in Y:
        list_y[int(y)] += 1

    for i in range(9, -1, -1):
        answer += (str(i) * min(list_x[i], list_y[i]))
    
    if answer == '':
        answer = '-1'
    elif answer[0] == '0':
        answer = '0'
    return answer