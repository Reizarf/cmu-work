# The program will take 5 different user inputs and determine whether or not "FBI" is in the input string.
# If there is an instance of "FBI", there will be a number assigned to which input it is present.
# 
# The program is taking 5 inputs and searching for "FBI"
# If there is an instance of "FBI", a number is placed in the position of input and then printed out.
# If there is not an instance of "FBI", the program prinds "HE GOT AWAY!" and is terminated.
import sys

test = ["FBI","FBI","FBI","FBI","FBI"]
test1 = ["TEST","TEST123","TESTFBI123","TESTFBI123","TESTABC123FBI"]
test2 = ["TEST", "RANDOM","RAND123","RANDALL","STEVE"]
def checkFBI(stringarray):
    output = []
    for i in range (0,5):
        if "FBI" in stringarray[i]:
            output.append(i+1)
        # else:
        #     output.clear()
        #     output.append("HE GOT AWAY!")
        #     break
    if len(output) != 0:
        return output
    else:
        return ["HE GOT AWAY!"]

def assertFunct():
    print(checkFBI(test))
    assert(checkFBI(test) == [1, 2, 3, 4, 5])
    assert(checkFBI(test1) == [3,4,5])
    assert(checkFBI(test2) == ["HE GOT AWAY!"])

stringarray = []
def solve():
    for test in range (1,6,1):
        input1 = input()
        stringarray.append(input1)
        #print(stringarray)
    array = checkFBI(stringarray)
    for i in range(len(array)):
        print(array[i], end = ' ')


if __name__ == "__main__":
    if len(sys.argv) >= 2 and sys.argv[1] == "test":
        assertFunct()
    else:
        solve()
