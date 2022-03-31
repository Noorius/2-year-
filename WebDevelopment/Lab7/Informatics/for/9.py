a = int(input())
summa = 0

for i in range(1,int((a)**(1/2))):
    if(a%i==0):
        summa+=1

summa *= 2;
if(a**(1/2)==int(a**(1/2))):
    summa += 1 

print(summa,end=" ")