def solution(lottos, win_nums):
    result = [6, 6, 5, 4, 3, 2, 1] ;
    min_idx = 0
    max_idx = 0
    for lotto in lottos:
        if lotto in win_nums: min_idx += 1
        if lotto == 0: max_idx += 1
    
    return [result[max_idx + min_idx], result[min_idx]]