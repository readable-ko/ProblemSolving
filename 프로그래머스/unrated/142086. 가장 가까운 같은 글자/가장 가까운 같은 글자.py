def solution(s):
    answer = []
    mp = {}
    for idx, val in enumerate(s):
        if mp.get(val) == None:
            answer.append(-1)
        else:
            answer.append(idx - mp[val])
        
        mp[val] = idx
    return answer