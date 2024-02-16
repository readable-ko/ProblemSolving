from collections import defaultdict
import sys
N, K = map(int, sys.stdin.readline().split())
numbers = list(map(int, sys.stdin.readline().split()))
numbers = sorted(numbers)
saved = [0 for _ in range(K)]
visited = defaultdict(int)

def permutation(depth):
    global saved, numbers
    if depth == K:
        for num in saved:
            print(num, end=" ")
        print()
        return
    
    for val in numbers:
        if not visited[val]:
            visited[val] = True
            saved[depth] = val
            permutation(depth+1)
            visited[val] = False

permutation(0)