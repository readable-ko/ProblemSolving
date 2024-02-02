import sys
N = int(sys.stdin.readline())
paper = [list(map(int,sys.stdin.readline().split())) for _ in range(N)]
style = {0:0, 1:0, -1:0}

def CuttingPaper(size, row, col):
    subSize = size // 3
    point = paper[row][col]
    
    for r in range(row, row + size):
        for c in range(col, col + size):
            if paper[r][c] != point:
                for i in range(3):
                    for j in range(3):
                        CuttingPaper(subSize, row + i * subSize, col + j * subSize)
                return
    
    style[point] += 1
    return


CuttingPaper(N, 0, 0)
for idx in [-1,0,1]:
    print(style[idx])