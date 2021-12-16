ip = input().split('.')

if(len(ip)!=4):
    print("NO")
    exit;

for i in ip:
    if(int(i)<0 or int(i)>255):
        print("NO")
        exit

print("YES")

