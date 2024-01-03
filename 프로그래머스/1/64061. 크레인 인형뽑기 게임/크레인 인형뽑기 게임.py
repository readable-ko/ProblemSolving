bucket = []
answer = 0

def _pick(board, number):
    item = 0
    for idx in range(len(board[number])):
        picked_item = board[number][idx]
        if picked_item != 0:
            item = picked_item
            board[number][idx] = 0
            return item
    return item

def pick(board, number):
    global answer
    item = _pick(board, number)
    
    if item == 0:
        return
    
    if len(bucket) and bucket[-1] == item:
        bucket.pop()
        answer+=2
        return
    
    bucket.append(item)
    return

def solution(board, moves):
    board = [list(x) for x in zip(*board)]
    
    for move in moves:
        pick(board, move - 1)
    return answer