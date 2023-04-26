def solution(s):
    answer = 0
    c = ''
    same, diff = 1, 0
    c = s[0]
    
    for alph in s[1:]:
        if same == diff:
            diff = 0
            same = 1
            answer += 1
            c = alph
            
        elif alph == c:
            same += 1
        else:
            diff += 1
    
    return answer + 1