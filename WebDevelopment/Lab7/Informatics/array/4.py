n = int(input())
arr = input().split(" ")
summa = 0
for i in range(1,n):
    if(int(arr[i])>int(arr[i-1])):
        summa+=1
        
print(summa, end=' ')