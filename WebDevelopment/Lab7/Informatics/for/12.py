n = input()
n = n[::-1]


summa = 0
for i in range(len(n)):
    if(n[i]=='1'):
        summa+=pow(2,i)

print(summa,end=" ")
