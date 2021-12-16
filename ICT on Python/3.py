'''print("Celsius - Fahrenheit.")
for i in range(0,101,10):
    print(str(i)+"       -   "+str(i*(9/5)+32))'''

pi = 3
for i in range(2,3,2):
    temp = (4/(i*i+1*i+2))
    if((i/2+1)%2!=0):
        temp = -temp 
    pi += temp
print(pi)

