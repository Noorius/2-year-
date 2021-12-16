#1
'''
sum = 0
size = input("size = ")
pep = True if input("add_pepperoni = ")=="Y" else False
sum += 1 if input("extra_cheese = ")=="Y" else 0

if(size=="S"):
    sum+= 17 if pep else 15
elif(size=="M"):
    sum+= 23 if pep else 20
elif(size=="L"):
    sum+= 28 if pep else 25

print("Your final bill is: $" + str(sum))'''

#2
'''
n = int(input())
res = "Not leap year"
if(n%4 == 0):
    if(n%100==0):
        if(n%400==0):
            res = "Leap year"
    else:
        res = "Leap year"

print(res)'''

#3
'''
w = float(input("weight = "))
h = float(input("height = "))
bmi = w / (h*h)

if(bmi<=18.5):
    print("You are underweight")
elif(25>=bmi>18.5):
    print("You are normal weight")
elif(30>=bmi>25):
    print("You are slighty overweight")
elif(35>=bmi>30):
    print("You are obese")
elif(bmi>35):
    print("You are clinically obese")

print(str(w)+" : ("+str(h)+" * "+str(h)+") = "+str(bmi))'''

#4
'''
s = float(input("Salary = "))
y = int(input("Years = "))

if(y>5):
    print("Your bonus is $"+str(0.05*s))
else:
    print("You have to work >5 years")'''

#5
'''
if(float(input("Length = "))==float(input("Breadth = "))):
    print("This is a square")
else:
    print("This is not a square")'''

#6
'''
q = int(input("Quantity = "))
sum = q * 100
if(q>1000):
    print("10% Discount! Your summary is "+str(sum - sum * 0.1))
else:
    print("Your summary is "+str(sum))'''

#7
'''
m = float(input())
if(m<25):
    print("F")
elif(25<=m<45):
    print("E")
elif(45<=m<50):
    print("D")
elif(50<=m<60):
    print("C")
elif(60<=m<80):
    print("B")
elif(m>=80):
    print("A")'''

#8
'''
m = {int(input()), int(input()), int(input())}
#print("The oldest age is "+str(max(m)))
#print("The youngest age is "+str(min(m)))

maxi = -1
mini = 1000
for i in m:
    if(i>maxi):
        maxi = i
    if(i<mini):
        mini = i

print("The oldest age is "+str(maxi))
print("The youngest age is "+str(mini))'''

#9
'''
total_class = int(input())
att_class = int(input())
per_att = float((att_class * 100) / total_class)

print("You have attended "+str(per_att)+" of classes")
if(per_att>=75):
    print("You are allowed for the exam")
else:
    print("Examin is not allowed")'''

#10
'''
number = input()
if(int(number[len(number)-1]) % 3 == 0):
    print("Divisible by 3")
else:
    print("Last digit is not divisible by 3")'''
