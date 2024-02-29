import sys
import heapq

N, M, X = map(int,sys.stdin.readline().split())
graph = [[] for _ in range(N+1)]
reverse_graph = [[] for _ in range(N+1)]

def find_path(sp, g):
    dist = [0x3f3f3f3f for _ in range(N+1)]
    pq = []
    heapq.heappush(pq, (sp, 0))
    while len(pq):
        ep, time = heapq.heappop(pq)
        for branch, t in g[ep]:
            if dist[branch] > time + t:
                dist[branch] = time + t
                heapq.heappush(pq, (branch, time + t))
        
    return dist

for _ in range(M):
    sp, ep, time = map(int,sys.stdin.readline().split())
    graph[sp].append((ep, time))
    reverse_graph[ep].append((sp, time))

fromX = find_path(X, graph)
toX = find_path(X, reverse_graph)

print(max([fromX[i] + toX[i] for i in range(1,N+1) if i != X]))