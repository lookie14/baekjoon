N ,M = map(int, input().split())
arr1 = [0 for _ in range(N+M)]
arr2 = list(map(int, input().split()))
for i in range(N):
    arr1[i] += arr2[i]
for i in range(N):
    arr3 = list(map(int, input().split()))
    for j in range(N+M):
        arr1[i] -= arr3[j]
        arr1[j] += arr3[j]
for i in range(N+M):
    print(arr1[i], end = ' ')
