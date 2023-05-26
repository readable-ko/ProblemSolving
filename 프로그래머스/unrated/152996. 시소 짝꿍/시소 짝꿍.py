from itertools import combinations
# 1, 3/2 4/2, 4/3, 2/3, 1/2, 3/4
def solution(weights):
    answer = 0
    cnt = [0 for _ in range(1001)]
    
    for w in weights:
        cnt[w] += 1
    
    for idx in weights:
        if idx % 2 == 0:
            base = int(idx * 1 // 2)
            if base <= 1000:
                answer += cnt[base]
        if idx % 3 == 0:
            base = int(idx * 2 // 3)
            if base <= 1000:
                answer += cnt[base]
        if idx % 4 == 0:
            base = int(idx * 3 // 4)
            if base <= 1000:
                answer += cnt[base]
    
    for num in cnt:
        if num >= 2:
            answer += num * (num - 1) // 2
    return answer