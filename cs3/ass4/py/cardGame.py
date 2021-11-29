import random, itertools
#generate deck
deck = list(itertools.product(range(1,14),['Spade','Heart','Diamond','Club']))

cardNum = ("two","three","four","five","six","seven","eight","nine","ten",
"jack","queen","king")

suit = ("diamonds","hearts","clubs","spades")


def randomFaceValue(cardNum):#generate random face
    randomFace = random.choice(cardNum)
    print("Random card is: ",randomFace)
    return randomFace

def randomSuitValue(suit):
    randomSuit = random.choice(suit)
    print("Random suit: ",randomSuit)
    return randomSuit

def randomBOTH(cardNum,suit):
    random_card = randomFaceValue,randomSuitValue
    return random_card


def guessCardNum(randomFace):
    print("randomFaceValue:",randomFace)
    guess = str(input("Enter your guess: (ex)'six','seven'."))
    print("Your guess was: ",guess)
    if(guess == cardNum):
        print("You were correct!")
        
    else:
        print("Guess again")
        



  
print('''
    Enter your selction:

    Guess only Face Value(A)
    Guess only suit(B)
    Guess face and suit(C)
    Quit(Q)
     ''')

selection = input()

print(selection)
while(selection != 'Q'):
    
    

    if(selection == 'A'):
        randomFaceValue(cardNum)#random card number
        print("Guessing face value")
        #guessCardNum()

        break
        #function call
    if(selection == 'B'):
        randomSuitValue(suit)#random suit value
        print("You chose to guess the suit value")
        #function call

        break
    if(selection == 'C'):
        #function call
        randomBOTH(cardNum,suit)
        print("Guess the face first then the suit")

        break


    