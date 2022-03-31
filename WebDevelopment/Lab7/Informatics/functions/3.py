def ili(a: int, p: int): return a+p==1

c = input().split(" ")
print(1 if ili(int(c[0]), int(c[1])) else 0)