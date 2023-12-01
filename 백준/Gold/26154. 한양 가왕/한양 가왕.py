N, M = map(int, input().split())
if M > 2*N:
    M = 2*N + (M%N)
room = [[] for _ in range(N)]
for i in range(N):
    a, b = map(int, input().split())
    room[i].append(a)
    room[i].append(b)
for _ in range(M):
    df = room[0][1] if room[0][0] > room[0][1] else room[0][0]
    room[0].remove(df)
    room[N-1].append(df)
    for i in range(1,N):
        win = room[i][1] if room[i][0] < room[i][1] else room[i][0]
        room[i].remove(win)
        room[i-1].append(win)

for i in range(N):
    room[i].sort()
    print(room[i][0],room[i][1])
