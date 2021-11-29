import random, itertools
#generate deck
deck = list(itertools.product(range(1,14),['Spade','Heart','Diamond','Club']))

cardNum = ("two","three","four","five","six","seven","eight","nine","ten",
"jack","queen","king")

suit = ("diamonds","hearts","clubs","spades")


def randomFaceValue(cardNum):#generate random face
    randomFace = random.choice(cardNum)
    print("Random card is: ",randomFace)
    print("Enter your guess: (ex)'six','seven'.")
    x = input()
    print("x",x)
    while(True):
        if(x == randomFace):
            print("You guessed correctly!")
            break
        else:
            print("Incorrect, guess again.")
            x = input()
            continue
    return randomFace

def randomSuitValue(suit):
    randomSuit = random.choice(suit)
    print("Random suit is: ",randomSuit)
    print("Enter your guess: ")
    x = input()
    print("you entered: ",x)
    while(True):
        if(x == randomSuit):
            print("You guessed correctly!")
            break
        else:
            print("Incorrect, guess again.")
            x = input()
            continue
    return randomSuit

def randomBOTH(cardNum,suit):
    random_card = randomFaceValue,randomSuitValue
    
    print("Option C:",random_card)
    return

# def guessCardNum(randomFace):
#     print("randomFaceValue:",randomFace)
#     guess = str(input("Enter your guess: (ex)'six','seven'."))
#     print("Your guess was: ",guess)
#     if(guess == cardNum):
#         print("You were correct!")
        
#     else:
#         print("Guess again")
        


def menu():
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
        if(selection == 'a' or 'A'):
            randomFaceValue(cardNum)#random card number
            print("Guessing face value")
            #guessCardNum()

            break
            #function call
        if(selection == 'b'):#not going into here for some reason
            print("here")
            randomSuitValue(suit)#random suit value
            print("You chose to guess the suit value")
            #function call

            break
        if(selection == 'c' or 'C'):
            #function call
            randomBOTH(cardNum,suit)
            print("Guess the face first then the suit")

            break
        break

menu()