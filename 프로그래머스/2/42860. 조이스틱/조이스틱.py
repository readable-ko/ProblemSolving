from itertools import permutations
answer = 0x3f3f3f3f
visited = [False for _ in range(21)]

def permutation(positions, selected, prev, asciiName, test):
    global answer, visited
    if len(selected) == len(positions):
        answer = min(answer, sum(selected) + sum(asciiName))
        return
    
    for idx in positions:
        if not visited[idx]:
            visited[idx] = True
            element = [min(abs(prev - idx), len(asciiName) - abs(prev - idx))]
            permutation(positions, selected + element, idx, asciiName, test + [idx])
            visited[idx] = False

def solution(names):
    global answer, visited
    asciiName = [min(ord(n) - ord('A'), abs(26 - ord(n) + ord('A'))) for n in names]
    positions = []
    
    for idx, name in enumerate(asciiName):
        if name != 0:
            positions.append(idx)
    
    if len(positions) == 0:
        answer = 0
    
    for idx in positions:
        visited[idx] = True
        permutation(positions,[min(idx,len(asciiName) - idx)], idx, asciiName, [idx])
        visited[idx] = False
        
    return answer