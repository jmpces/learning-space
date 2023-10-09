from ctypes import *
from vector import IntVector, IntVectorCreate

test = IntVectorCreate([1,3,5,7,9,11,15])

print(type(test))

a = IntVector()
a.append(5)
a.append(10)
a.append(15)
a.append(20)

print('a = ', a, sep="")
print('a size :', a.size())

print("test : ")
for i in test:
    print(i,end=" ")
print("")