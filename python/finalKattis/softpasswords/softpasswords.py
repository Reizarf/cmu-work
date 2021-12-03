
S = input()
P = input()

def problem(S,P):
    works = (S == P) or pre(S,P) or app(S,P) or (S == P.swapcase())
    print('Yes' if works else 'No')
    if(works):
        return 'Yes'
    if(not works):
        return 'No'

def pre(S,P):
    for i in range(10):
        if (str(i) + P) == S:
            return True
    return False


def app(S,P):
    for i in range(10):
        if (P + str(i)) == S:
            return True
    return False


problem(S,P)

#works = (S == P) or pre() or app() or (S == P.swapcase())
#print('Yes' if works else 'No')