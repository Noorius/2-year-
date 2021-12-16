''' s = input("Hello World!")
rem = int(input("Please inter i-th element in string to remove it."))

print(s[0:rem]+s[rem+1:len(s)]) '''

'''
s = input("Input string ").split()
print("Words with odd chars are:\n")
for i in s:
    if(len(i)%2 == 0):
        print(i)'''

'''
s = input("A word to count is ")
cnt = 0;
for i in s.strip():
    cnt+=1
print("Number of letters in word is " + str(cnt))'''

'''
s = input("text: ")
t = input("word: ")
print("Found? " + "True" if t in s else "False")'''

'''
s = input("Dots input: ")
print("Commas output: \n"+s.replace(".",","))'''