
a = int(input())
b = int(input())

for i in range(a,b+1):
    root = i**(1/2)
    if(root==int(root)):
        print(i, end=' ')