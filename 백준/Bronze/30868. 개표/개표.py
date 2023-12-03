import sys
input = sys.stdin.readline
T = int(input())
for _ in range(T):
    a = int(input())
    b = a//5
    c = a%5
    for i in range(b):
        print('++++', end = ' ')
    for i in range(c):
        print('|' ,  end='')
    print()
