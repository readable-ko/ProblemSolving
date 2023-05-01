import re
def solution(dartResult):
    bonus = {'S':1, 'D':2, 'T':3}
    opt = {'':1, '*':2, '#':-1}
    p = re.compile('(\d+)([STD])([*#]?)')
    darts = p.findall(dartResult)
    
    for i in range(len(darts)):
        if darts[i][-1] == '*' and i > 0 :
            darts[i - 1] *= 2
        darts[i] = int(darts[i][0]) ** bonus[darts[i][1]] * opt[darts[i][2]]
    return sum(darts)