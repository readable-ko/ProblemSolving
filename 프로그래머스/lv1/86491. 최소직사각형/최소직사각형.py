def solution(sizes):
    w, h = 0, 0
    
    for size in sizes:
        width, height = max(size[0], size[1]), min(size[0], size[1])
        w = max(width, w)
        h = max(height, h)
    
    return w * h