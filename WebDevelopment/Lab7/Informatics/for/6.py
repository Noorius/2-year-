from audioop import reverse


a = int(input())

summa = ""

while(a==int(a)):
    a /= 10
a*=10
a = str(int(a))

for i in reversed(a):
    summa += i

print(summa)
