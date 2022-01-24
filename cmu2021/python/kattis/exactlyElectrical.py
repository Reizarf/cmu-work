a,b = map(int,input().split)
c,d = map(int,input().split)
t = int(input())

yDistance = abs(b-d)

xDistance = abs(a-c)

total = yDistance + xDistance

if t - total < 0:
    print("N")

elif(t-total) % 2 == 0:
    print("Y")
else:
    print("N")


#more kattis problems to look at?

#https://open.kattis.com/problems/gold
#https://open.kattis.com/problems/conquestcampaign
#https://open.kattis.com/problems/exactlyelectrical

#github
#https://github.com/gkamtzir/Kattis-Problems