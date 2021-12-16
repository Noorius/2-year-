age = int(input("Enter age "))
sex = input("Enter sex ")
m = input("Enter marital status ")

if(age<20 or age>60):
    print("ERROR")
    exit(0)
if(sex == "F"):
    print("Urban Area only")
else:
    if(20<=age<40):
        print("Anywhere")
    elif(40<=age<=60):
        print("Urban areas only")