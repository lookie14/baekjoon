import sys
from collections import deque
input = sys.stdin.readline

def bfs(start, find):
    Q = deque()
    Q.append((start, 0))
    visited = [False]* (N+1)
    visited[start] = True

    while Q:
        v, d = Q.popleft()
        if v == find:
            return d
        for i, j in arr[v]:
            if not visited[i]:
                visited[i] = True
                Q.append((i,j+d))

N, M = map(int, input().split())
arr = [[] for _ in range(N+1)]
for i in range(N-1):
    a,b,D = map(int, input().split())
    arr[a].append((b,D))
    arr[b].append((a,D))
for _ in range(M):
    x1, x2 =  map(int, input().split())
    print(bfs(x1,x2))
    
