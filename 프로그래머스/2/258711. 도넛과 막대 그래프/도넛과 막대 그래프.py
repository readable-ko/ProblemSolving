def solution(edges):
    IN, OUT = 0,1
    inAndOut = [[0,0] for _ in range(1000001)]
    
    for edge in edges:
        inAndOut[edge[0]][OUT] += 1
        inAndOut[edge[1]][IN] += 1
    
    stick, eight, total, sp = 0,0,0,0
    for idx, value in enumerate(inAndOut):
        if value[IN] == 0 and value[OUT] == 0:
            continue
        
        if value[IN] == 0 and total < value[OUT]:
            total = value[OUT]
            sp = idx
            
        elif value[OUT] == 0:
            stick += 1
            
        elif value[IN] >= 2 and value[OUT] == 2:
            eight += 1
        
    answer = [sp, total - stick - eight, stick, eight]
    return answer