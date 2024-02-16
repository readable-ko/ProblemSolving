def solution(n):
    answer = []
    """
    2: [1 2] [1 3] [2 3]
    3: [1 2] [1 3] [2 3] [1 2] [3 2] [3 1] [2 1] [2 3] [1 2] [1 3] [2 3]
    2: hanoi(1) -> [1 3] [2 3]
    3: hanoi(2) -> hanoi(1) 
    """
    def hanoi(N, sp, ep, tmp):
        if N == 1:
            answer.append([sp, ep])
            return
        
        hanoi(N-1, sp, tmp, ep)
        answer.append([sp, ep])
        hanoi(N-1, tmp, ep, sp)
        
    hanoi(n, 1, 3, 2)
    return answer