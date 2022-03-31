def is_leap(n):
    leap = False
    
    return ((n%4 == 0) and (n%100!=0)) or (n%400==0)

year = int(input())
print(is_leap(year))
