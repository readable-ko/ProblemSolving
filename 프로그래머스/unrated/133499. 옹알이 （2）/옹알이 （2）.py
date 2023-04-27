import re
def solution(babbling):
    answer = 0
    can = ['aya', 'ye', 'woo', 'ma']
    
    for speak in babbling:
        for idx in range(4):
            speak = re.sub(can[idx], str(idx), speak)
        
        if re.search('\D', speak):
            continue
        
        flag = True
        for i in range(1, len(speak)):
            if speak[i] == speak[i-1]:
                flag = False
                break
        
        if flag: answer += 1
    return answer