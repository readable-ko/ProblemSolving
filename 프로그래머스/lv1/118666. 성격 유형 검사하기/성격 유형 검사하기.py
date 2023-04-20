def solution(survey, choices):
    opposite = {'R':'T', 'C':'F', 'J':'M', 'A':'N'}
    answer = ''
    mp = {'R':0, 'C':0, 'J':0, 'A':0}
    for i in range(len(survey)):
        if survey[i][0] in mp.keys():
            mp[survey[i][0]] -= (choices[i] - 4)
        else:
            mp[survey[i][1]] += (choices[i] - 4)
    
    for it in mp.keys():
        if mp[it] >= 0:
            answer += it
        else:
            answer += opposite[it]
    return answer