n = int(input("Enter number of terms: "))

prev = 0 #первое число всегда 0
next = 1 #второе всегда 1

print("Fibonacci sequence: ")

for i in range(0,n): #продолжаем цикл 10 раз так как нужно 10 чисел
    print(prev,end=" ") #печатем одно число предыдущее
    temp = next #нужно сохранить значение некст
    next = prev + next #некст получаем прибавлением двух предыдущих
    prev = temp #а предыдущее двигается вперед 