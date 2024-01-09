LEFT = 0
MID = 1
RIGHT = 2
MOD = 10007

def solution(n, tops):
    answer = 0
    tiles = [[0 for _ in range(3)] for _ in range(n)]
    
    for idx in range(n):
        top = tops[idx]
        if idx == 0:
            tiles[idx] = [1, 1 + top, 1]
        else:
            next_left = (tiles[idx - 1][LEFT] + tiles[idx-1][MID] + tiles[idx-1][RIGHT]) % MOD
            next_mid = (next_left * (1 + top)) % MOD
            next_right = tiles[idx -1][MID] + tiles[idx-1][RIGHT] % MOD
            tiles[idx] = [next_left, next_mid, next_right]
    
    answer = sum(tiles[n-1]) % MOD
    return answer