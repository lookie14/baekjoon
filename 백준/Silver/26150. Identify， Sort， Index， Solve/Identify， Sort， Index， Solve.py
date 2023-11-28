N = int(input())
arr = []
for _ in range(N):
    arr.append(input().split())
arr.sort(key=lambda x:int(x[1]))
ans = ''
for st in arr:
    a = ord(st[0][int(st[2])-1])
    if a>=97:
        a -=32
    ans += chr(a)
print(ans)
