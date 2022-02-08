
# I declare that all material in this assessment task is
# my work except where there is clear acknowledgement
# or reference to the work of others. I further declared
# that I have complied to the CMU Academic Integrity
# policy at the University Website. 
# https://coloradomesa.edu/student-services/documents
# Authors Name:       Sullivan Frazier
# UID(700#:)          700-479463
# Date:               1 December 2021

# Submissions that do not include the above academic 
# integrity statement will not be considered.


import random, itertools

cardNum = ("two","three","four","five","six","seven","eight","nine","ten",
"jack","queen","king")

suit = ("diamonds","hearts","clubs","spades")


def randomFaceValue(cardNum):#generate random face
    randomFace = random.choice(cardNum)
    #print("Random card is: ",randomFace)
    print("Enter your guess: (ex) 'six','seven','king','jack' etc.")
    x = input()
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
    #print("Random suit is: ",randomSuit)
    print("Enter your guess: (ex) 'spades','clubs','hearts','diamonds'.")
    x = input()
    
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
    random_card = randomFaceValue(cardNum),randomSuitValue(suit)
    
    # print("Option C:",random_card)
    return   

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
    while(selection != 'q'):
        if(selection == 'a' or selection == 'A'):
            randomFaceValue(cardNum)#random card number
            print("Guessing face value")
            #guessCardNum()
            menu()
            break#play with continue
            #function call
        elif(selection == 'b' or selection == 'B'):#not going into here for some reason
            print("You chose to guess the suit value")
            randomSuitValue(suit)#random suit value
            
            #function call
            menu()
            break
        elif(selection == 'c' or selection == 'C'):
            #function call
            print("Guess the face first then the suit")
            randomBOTH(cardNum,suit)
            
            menu()
            break
       
#randomSuitValue(suit)
menu()