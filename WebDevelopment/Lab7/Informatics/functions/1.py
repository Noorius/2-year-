def mini(a: int, b: int, c:int, d:int):
    return min(min(a,b),min(c,d))

c = input().split(" ")
print(mini(int(c[0]),int(c[1]),int(c[2]),int(c[3])))
