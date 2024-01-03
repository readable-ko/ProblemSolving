import sys
N, M = map(int,sys.stdin.readline().split())
board = []

for i in range(N):
    list = [1 if x == "B" else 0 for x in sys.stdin.readline().strip()]
    board.append(list)
    
minimum = 64
for i in range(N - 7):
    for j in range(M - 7):
        black, white = 0, 1
        black_diff, white_diff = 0,0

        for x in range(i, i+8):
            black, white = white, black
            for y in range(j, j+8):
                if black != board[x][y]:
                    black_diff+=1
                if white != board[x][y]:
                    white_diff+=1
                black, white = white, black

        minimum = min(black_diff, white_diff, minimum)

print(minimum)