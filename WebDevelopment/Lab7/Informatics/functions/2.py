def power(a: float, p: int): return pow(a,p)

c = input().split(" ")
print(power(float(c[0]), int(c[1])))