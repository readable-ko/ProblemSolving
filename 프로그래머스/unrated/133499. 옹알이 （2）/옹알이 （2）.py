import re
def solution(babbling):
    answer = 0
    can = ['aya', 'ye', 'woo', 'ma']
    
    for speak in babbling:
        for idx in range(4):
            if can[idx]*2 not in speak:
                speak = re.sub(can[idx], str(1), speak)
        
        if re.search('\D', speak):
            continue
        
        answer += 1
    return answer