def solution(survey, choices):
    answer = ["R","C", "J", "A"]
    mp = {'R':0, 'C':0, 'J':0, 'A':0}
    for i in range(len(survey)):
        if survey[i][0] in "RCJA":
            mp[survey[i][0]] -= (choices[i] - 4)
        else:
            mp[survey[i][1]] += (choices[i] - 4)
    
    if mp['R'] < 0 : answer[0] = "T"
    if mp['C'] < 0 : answer[1] = 'F'
    if mp['J'] < 0 : answer[2] = 'M'
    if mp['A'] < 0 : answer[3] = 'N'
    return ('').join(answer)