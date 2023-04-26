def solution(number, limit, power):
    answer = 0
    cnt = [0] * (number + 1)
    
    for i in range(1, number + 1):
        for j in range(i, number + 1, i):
            cnt[j] += 1
            
        if cnt[i] > limit:
            answer += power
        else:
            answer += cnt[i]

    return answer