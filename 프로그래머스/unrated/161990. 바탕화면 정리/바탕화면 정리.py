def solution(wallpaper):
    drag = [51, 51, 0, 0]
    for i, paper in enumerate(wallpaper):
        for j, wall in enumerate(paper):
            if wall == '#':
                x_pos = int(i)
                y_pos = int(j)
                drag[0] = min(x_pos, drag[0])
                drag[2] = max(x_pos + 1, drag[2])
                drag[1] = min(y_pos, drag[1])
                drag[3] = max(y_pos + 1, drag[3])
    
    return drag