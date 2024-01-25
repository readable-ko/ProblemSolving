import copy

def solution(park, routes):
    dog = [0,0]
    for i in range(len(park)):
        for j in range(len(park[0])):
            if park[i][j] == 'S':
                dog[0] = i
                dog[1] = j
                
    direction = {'E': [0,1], 'W': [0,-1], 'N': [-1, 0], 'S':[1,0]}
    
    for route in routes:
        way, distance = route.split()
        new_pos = dog.copy()
        for i in range(1, int(distance)+1):
            new_pos[0] += direction[way][0]
            new_pos[1] += direction[way][1]
            if new_pos[0] < 0 or new_pos[0] >= len(park) or new_pos[1] < 0 or new_pos[1] >= len(park[0]):
                new_pos = dog
                break ;
            if park[new_pos[0]][new_pos[1]] == 'X':
                new_pos = dog
                break ;
        dog = new_pos
    return dog