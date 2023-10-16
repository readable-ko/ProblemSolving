from itertools import combinations
from math import ceil, floor
def solution(line):
    points = []
    answer = []

    for combo in combinations(line, 2):
        a, b, e = combo[0]
        c, d, f = combo[1]
        if a * d - b * c == 0:
            continue
            
        x = (b * f - e * d) / (a * d - b * c)
        y = (e * c - a * f) / (a * d - b * c)
        if ceil(x) == floor(x) and ceil(y) == floor(y):
            points.append([int(x), int(y)])
    
    min_y = min(y[1] for y in points)
    max_y = max(y[1] for y in points)
    max_x = max(x[0] for x in points)
    min_x = min(x[0] for x in points)
    
    for y in range(max_y, min_y - 1, -1):
        line = ""
        for x in range(min_x, max_x + 1):
            if [x, y] in points:
                line += "*"
            else:
                line += "."
        answer.append(line)

    return answer