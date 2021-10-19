#referenced  https://github.com/ionelh/kattis/blob/master/python3/solutions/anotherbrick.py

import sys

header = [int(x) for x in sys.stdin.readline().split()]
bricks = [int(x) for x in sys.stdin.readline().split()]

target_width = header[1]
target_height = header[0]

row_w = 0
rows = 0

result = ''

for brick in bricks:
    row_w += brick

    if row_w == target_width:
        rows +=1

        if rows == target_height:
            result = 'YES'
            break
        row_w = 0

    if row_w > target_width:
        result = 'NO'
        break
print(result)

