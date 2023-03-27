def convertNum(x, y):
    result = 50 * (x - 1)
    return result + y

def update_cell(r, c, value, cell, parent):
    now = find_parent(convertNum(r,c), parent)
    cell[now] = value
    
def update_data(value1, value2, cell):
    for i in range(1, 2501):
        if cell[i] == value1:
            cell[i] = value2

def find_parent(val, parent):
    if val != parent[val]:
        parent[val] = find_parent(parent[val], parent)
    return parent[val]

def merge_data(r1, c1, r2, c2,cell, parent):
    parent2 = find_parent(convertNum(r2,c2), parent)
    parent1 = find_parent(convertNum(r1,c1), parent)
    if parent2 == parent1:
        return
    elif cell[parent1] == "EMPTY":
        parent[parent1] = parent2
        
        for i in range(1, 2501):
            if parent[i] == parent1:
                parent[i] = parent2
        return
    else:
        parent[parent2] = parent1
        
        for i in range(1, 2501):
            if parent[i] == parent2:
                parent[i] = parent1
        return

def unmerge_data(r1, c1, parent, cell):
    now = convertNum(r1,c1)
    p = parent[now]
    root = cell[p]

    nodes = []
    for i in range(1, 2501):
        if parent[i] == p:
            nodes.append(i)
    
    for node in nodes:
        parent[node] = node
        cell[node] = "EMPTY"

    cell[now] = root

def solution(commands):
    answer = []
    cell = ["EMPTY" for i in range(2501)]
    parent = [j for j in range(2501)]
    
    for cmd in commands:
        prom = cmd.split(' ')
        if prom[0] == "UPDATE":
            if len(prom) == 4:
                update_cell(int(prom[1]), int(prom[2]), prom[3], cell, parent)
            else:
                update_data(prom[1], prom[2], cell)
        elif prom[0] == "MERGE":
            merge_data(int(prom[1]), int(prom[2]), int(prom[3]), int(prom[4]),cell, parent)
        elif prom[0] == "UNMERGE":
            unmerge_data(int(prom[1]), int(prom[2]), parent, cell)
        else:
            now = find_parent(convertNum(int(prom[1]), int(prom[2])), parent)
            answer.append(cell[now])
    return answer