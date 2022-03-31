n = int(input())
arr = input().split(" ")

for i in range(len(arr)):
    if(int(arr[i])%2==0):
        print(arr[i], end=' ')