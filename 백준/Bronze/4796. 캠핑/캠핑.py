num = 1
while(1) :
    L, P, V = map(int, input().split())
    if(L==0 and P == 0 and V == 0):
        break
    sum = 0
    sum += (V//P)*L
    if (V%P>=L):
        sum += L
    else:
        sum += V%P
    print("Case", str(num)+":", sum)
    num +=1
