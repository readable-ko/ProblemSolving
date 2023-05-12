import sys
from itertools import combinations
N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
face_side = [5,4,3,2,1,0]
treeple = [[0,1,2], [0,1,3], [0,2,4], [0,3,4], [1,2,5], [1,3,5], [2,4,5], [3,4,5]]

min_1 = min(arr)
min_2 = 0x3f3f3f3f
min_3 = 0x3f3f3f3f

for pair in combinations(range(6),2):
    if face_side[pair[0]] == pair[1]: continue
    min_2 = min(min_2, arr[pair[0]] + arr[pair[1]])

for idx in treeple:
    min_3 = min(min_3, arr[idx[0]] + arr[idx[1]] + arr[idx[2]])

if N == 1:
    min_5 = 0x3f3f3f3f
    for idx in range(6):
        min_5 = min(min_5, sum(arr) - arr[idx])
    print(min_5)
else:
    print((4 * min_3) + (4 * (N - 2) + 4 * (N - 1)) * min_2 + ((N - 2)*(N - 1) * 4 + (N - 2)* (N - 2)) * min_1)