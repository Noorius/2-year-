n = int(input())
res = "NO"

if(n%400==0):
    res = "YES"
elif(n%100==0):
    res = "NO"
elif(n%4==0):
    res = "YES"

print(res)