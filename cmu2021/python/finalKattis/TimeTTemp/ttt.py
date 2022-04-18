A,B = map(float, input().split())



def TimeTravellingTemperatures(A,B):
    if A == 1 and B == 0:
        ans = "ALL GOOD"
    elif B==1:
        ans = "IMPOSSIBLE"
    else:
        ans = (A/-(B-1))
    return ans

prob = TimeTravellingTemperatures(A,B)
print(prob)