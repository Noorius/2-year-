import math
# 1

#print("Refund for Bottles: $"+'%.2f'% (float(input("0.10: ")) * 0.10 + float(input("0.25: ")) * 0.25) );

# 2
#money = float(input("Cost of meal: ")) 

#print("$"+'%.2f'% (money + money * 0.05 + money * 0.18))

# 3

def summa(n: int):
    if(n == 0):
        return 0;
    return n + summa(n-1)

'''
import itertools
print([i for i in itertools.accumulate([x for x in range(1,int(input())+1)])].pop())
print(sum([i for i in range(1,int(input())+1)]))
'''

#m = int(input())
#print('%.0f'%((m+1)*m/2))

# 4

#print('%.0f'% (float(input("Widgets: ")) * 75 + float(input("Gizmos: ")) * 112) );

# 5
'''
m = float(input())

for i in range(1,4):
    m+=(m*0.04)
    print("After {} {}: $".format(i,("year" if i==1 else "years")),end=('%.2f\n'%m))
'''
# 6
'''
t = float(input("Temperature value in degree Celsius:  "))

print("The {} degree Celsius is equal to: {} Fahrenheit".format(t,'%.2f'%(t*1.8+32)))
print("The {} degree Celsius is equal to: {} Kelvin".format(t,'%.2f'%(t+273.15)))
'''
# 7
'''
t = int(input("Enter the air temperature in (degrees Celsius): "))
w = pow(float(input("Enter the wind speed (kilometer per hour): ")),0.16)

print("Your Wind Chill Index:",end=" ")
print('%.0f'%(13.12 + 0.6215 * t - 11.37 * w + 0.3965 * t * w))
'''
# 8
'''
h = pow(float(input("height ")),2)
w = float(input("weight "))
print("The BMI is "+'%.1f'%(w/h))
'''

# 9

#print(int(input("Days"))*pow(60,2)*24+int(input("Hours"))*pow(60,2)+int(input("Mins"))*60+int(input("Sec")))

#10
'''
secs = int(input()) #seconds

days = secs // (24 * 3600) 

secs = secs % (24 * 3600)

hours = secs // 3600 

secs = secs % 3600

minutes = secs // 60 

secs = secs % 60

print(days,":",hours,":",minutes,":",(secs if secs>9 else "0"+str(secs)))

'''
