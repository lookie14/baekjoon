import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    x, y = map(int, input().split())
    D = (y - x)
    cnt = 0
    move = 1
    mp = 0
    while mp < D:
        cnt += 1
        mp += move
        if cnt %2 == 0 :
            move += 1
    print(cnt)