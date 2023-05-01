def solution(dartResult):
    answer = 0
    dart = 0
    darts = []
    for i in dartResult:
        if i.isdigit():
            dart = dart*10 + int(i)
        elif i.isalpha():
            if i == 'D':
                dart = dart**2
            elif i == 'T':
                dart = dart**3
                
            darts.append(dart)
            dart = 0
        else:
            if i == '*':
                darts[-2:] = [i * 2 for i in darts[-2:]]
            elif i == '#':
                darts[-1:] = [i * -1 for i in darts[-1:]]
    
    print(darts)
    return sum(darts)