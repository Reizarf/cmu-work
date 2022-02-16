A,B,C,N = map(int, input("").split())

def moscowDream(A,B,C,N):
    if A == 0 or B == 0 or C == 0 or N < 3 or A+B+C <N:
        ans = "NO"
        #print("NO")
    else:
        ans = "YES"
        #print("YES")
    return ans

answer = moscowDream(A,B,C,N)
print(answer)