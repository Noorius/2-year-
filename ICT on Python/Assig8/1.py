#1
'''
vvod = int(input())
list_chisel = list( range(vvod,0,-1) )

size_n = len(list_chisel)

for i in range(0,size_n): 
    for j in list_chisel[i:size_n]: 
        print(j,end=" ")
    print()
'''

'''
#2
n = int(input("Enter number: "))
summa = 0
averag = 0.0

for i in range(1,n+1):
    summa = summa + i;

print("Sum of first "+str(n)+" numbers is: "+str(summa))
averag = summa / n
print("Average of "+str(n)+" numbers is: "+str(averag))
'''

'''
#3
list_chisel = input().split(' ') 

for element in list_chisel: 
    chislo = int(element) 
    if(chislo>300): 
        break 
    if(chislo % 3 != 0 or chislo>120):
        continue
    print(chislo) 
'''


#4
#'''
import math

start = int(input("start = "))
end = int(input("end = "))

print("Prime numbers between "+str(start)+" and "+str(end)+" are: ")

for i in range(start, end+1): 
    isPrime = True 
    for j in range(2,int(math.sqrt(i))+1): 
        if(i%j==0): 
            isPrime = False; 
            break; 
    if(isPrime==True): 
        print(i)
#'''

'''
#5

n = int(input("Enter number of terms: "))

prev = 0 
next = 1 

print("Fibonacci sequence: ")

for i in range(0,n): 
    print(prev,end=" ") 
    temp = next
    next = prev + next
    prev = temp 

'''