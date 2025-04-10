from itertools import combinations

def solution(n, q, ans):
    answer = 0
    sn = [set(arr) for arr in q]
    orgin = [i for i in range(1, n+1)]
    
    for k in combinations(orgin, 5):
        sk = set(k)
        flag = True
        for idx, s in enumerate(sn):
            if len(sk & s) != ans[idx]:
                flag = False
                break;
        
        if flag:
            answer += 1
            
    return answer