#referenced  https://github.com/ionelh/kattis/blob/master/python3/solutions/anotherbrick.py
import unittest
import sys

header = [int(x) for x in sys.stdin.readline().split()]
bricks = [int(x) for x in sys.stdin.readline().split()]

target_width = header[1]
target_height = header[0]

row_w = 0
rows = 0
def rows(rows):
    rows+=1

result = ''
def brick():
    row_w = 0
    rows = 0
    for brick in bricks:
        row_w += brick
        if row_w == target_width:
            #rows +=1
            rows()
            if rows == target_height:
                result = 'YES'
                break
            row_w = 0

        if row_w > target_width:
            result = 'NO'
            break
    print(result)

class Tests(unittest.TestCase):
    def test(self):
        self.assertEquals(rows(rows),rows+1)

# if __name__ == '__main__':
#     unittest.main()

x = '2 10 7 5 5 5 5 5'
brick()

#print(int(x),base=16)

# one = list(input(x))
#print("one",one)