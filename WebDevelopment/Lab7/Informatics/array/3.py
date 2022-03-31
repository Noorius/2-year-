n = int(input())
arr = input().split(" ")
summa = 0
for i in range(n):
    if(int(arr[i])>0):
        summa+=1
        
print(summa, end=' ')