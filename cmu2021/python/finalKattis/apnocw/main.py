
# 
# n,x = map(int,input().split())


def aPrize(n,x,items):
    
    # n,x = map(int,input().split())
    
    if n == 1:
        print('1')
    elif items[-1] + items[-2] <= x:
        print(n)
    else:
        for i,c in enumerate(items):
            if c + items[i+1] > x:
                print(i+1)
                break
    return n


if __name__ == "__main__":
    
    n,x = map(int,input().split())
    print("split")
    items = sorted(map(int,input().split()))

    print("n=",n,"x=",x,"items=",items)

    aPrize(n,x)