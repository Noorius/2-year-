n = int(input())
arr = input().split(" ")
summa = False

for i in range(1,n):
    if(int(arr[i])*int(arr[i-1])>0):
        summa=True
        
print("YES" if summa else "NO")