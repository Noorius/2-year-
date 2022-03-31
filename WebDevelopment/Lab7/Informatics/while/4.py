n = int(input())
i = 0

while(pow(2,i)!=n):
    if(pow(2,i)>n):
        print("NO")
        exit(0)
    i+=1

print("YES")