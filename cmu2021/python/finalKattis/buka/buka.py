def main():
    a = int(input())
    operator = input()
    b = int(input())
    baka(a,operator,b)

def baka(a,operator,b):
    if(operator == "+"):
        c = a+b
        print(c)
    else:
        c = a*b
        print(c)
    return c

main()
