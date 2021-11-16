#https://open.kattis.com/problems/character

numofCharacters = int(input())
# print(2**numChar - numChar - 1)

def characters(numofCharacters):

    x = ((2**numofCharacters)-numofCharacters-1)
    #print(x)
    return x

print(characters(numofCharacters))