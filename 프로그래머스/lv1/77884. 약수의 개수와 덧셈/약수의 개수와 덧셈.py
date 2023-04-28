def solution(left, right):
    정답 = 0
    약수 = [0] * 1001
    반복 = max(left, right) + 1
    
    for i in range(1, 반복):
        for j in range(i, 반복):
            if j % i == 0:
                약수[j] += 1
    
    for i in range(left, right+1):
        if 약수[i] & 1 == 1:
            정답 -= i
        else:
            정답 += i
    return 정답