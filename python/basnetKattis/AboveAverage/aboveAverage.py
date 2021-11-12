import unittest


x = '5\n 50 50 50 70 80'

def aboveAverage(x):
    for _ in range(int(input())):

        scores = [int(x) for x in input().split()]
        nums = scores.pop(0)

        ans = sum([1/nums*100 for x in scores if x>sum(scores)/nums])

        print("{:.3f}%".format(ans))


#class TestAboveAverage():
    #def testAverage():
        #self.assertEqual(aboveAverage(x),y)


#y = '5\n 50 50 50 70 80'
#x = '5\n 50 50 50 70 80'
aboveAverage(int(x))

#x = 5;50;50;70;80;100
#assert aboveAverage(int(input(x))) == 40.000
#assert aboveAverage(5,50,50,70,80,100) == 20.000%


