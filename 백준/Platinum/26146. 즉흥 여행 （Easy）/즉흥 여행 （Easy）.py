import sys
input = sys.stdin.readline   

N, M = map(int, input().split())
mm = [[] for _ in range(N+1)]
mm2 = [[] for _ in range(N+1)]
check = [False for _ in range(N+1)]
check2 = [False for _ in range(N+1)]
for i in range(M):
    a,b = map(int, input().split())
    mm[a].append(b)
    mm2[b].append(a)

q = [1]
q2 = [1]
while(q):
    nxt = q.pop()
    if(check[nxt] == True):
        continue
    for i in mm[nxt]:
        q.append(i)
    check[nxt] = True
while(q2):
    nxt = q2.pop()
    if(check2[nxt] == True):
        continue
    for i in mm2[nxt]:
        q2.append(i)
    check2[nxt] = True


flag = 0
for i in range(1,N+1):
    if check[i] == False or check2[i] == False:
        print('No')
        flag = 1
        break
if flag == 0:
    print('Yes')
