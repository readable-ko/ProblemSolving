import sys
R, C = map(int,sys.stdin.readline().split())
dx = [-1,0,1]
board = []
answer = 0

def check(r, c = 0):
    board[r][c] = "x"
    
    if c + 1 == C:
        return True
    
    for dr in dx:
        next_r = r + dr
        if 0 <= next_r < R and board[next_r][c+1] != 'x':
            if check(next_r, c+1):
                return True
    
    return False

for row in range(R):
    board.append(list(sys.stdin.readline()[:-1]))
    

for sp in range(R):
    if check(sp):
        answer += 1

print(answer)