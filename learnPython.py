def print1():
    n = int(input("enter a num: "))
    for i in range (0, n):
        for j in range (0, n):
            print("*", end = " ")
        print( )

def print1():
    n = int(input("enter a num: "))
    for i in range (0, n):
        for j in range (0, i+1):
            print("*", end = " ")
        print( )  

def main():
    t = int(input("enter t: "))
    for i in range(0, t):
        print1()

main()



