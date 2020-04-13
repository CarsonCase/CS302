import random

def printInts(size, maxSize, minSize = 0):
    intArray = []
    for i in range(0,size):
        intArray.append(random.randint(minSize,maxSize))
    with open('data.txt', 'w') as outfile:
        for i in intArray:
            outfile.write(str(i)+" ")

s = input("What is the size of the array? ")
ms = input("What is the max size of the intergers? ")
printInts(int(s),int(ms))
print("data saved to data.txt")