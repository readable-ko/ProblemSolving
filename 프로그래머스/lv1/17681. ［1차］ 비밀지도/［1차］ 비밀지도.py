def solution(n, arr1, arr2):
    answer = []
    
    for num1, num2 in zip(arr1, arr2):
        s = bin(num1 | num2)[2:].rjust(n, '0')
        s = s.replace('0', ' ')
        s = s.replace('1', '#')
        answer.append(s)
    return answer