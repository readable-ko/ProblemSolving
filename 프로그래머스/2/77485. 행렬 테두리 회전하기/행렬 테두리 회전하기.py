d_x = [0,1,0,-1]
d_y = [1,0,-1,0]
d_p = [0,0,0,0]

def rotate(matrix, sp, ep):
    now = sp.copy()
    keep = matrix[sp[0]][sp[1]]
    minimum = keep
    
    for dx, dy in zip(d_x,d_y):
        now[0] += dx
        now[1] += dy
        while sp[0] <= now[0] <= ep[0] and sp[1] <= now[1] <= ep[1]:
            keep, matrix[now[0]][now[1]] = matrix[now[0]][now[1]], keep
            minimum = min(keep, minimum)
            now[0] += dx
            now[1] += dy
        now[0] -= dx
        now[1] -= dy
    return minimum
    
def solution(rows, columns, queries):
    matrix = [[0 for x in range(columns+1)]]
    answer = []
    
    for i in range(rows):
        matrix.append([x+columns*i for x in range(columns+1)])
    for i in range(rows+1):
        print(matrix[i])
    for q in queries:
        answer.append(rotate(matrix, q[:2],q[2:]))
        
    return answer