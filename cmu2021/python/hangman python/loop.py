import random
print("Hello and welcome to the number guessing game! What's your name: ")
name = input()
print("Hello!",name)

print("Take a guess between 1 and 20")
global play
play = True
#str(input())

while play != False:
    play = True
    number_of_guesses = 1
    values = random.randint(0,20)
    #print(values)
    print("I am thinking of a number between 1 and 20, but \nyou only get 6 tries to guess the number. Take a guess!")
    while number_of_guesses != 6:
    #str(guess)

        guess = int(input())
        if guess == values:
            
            print("You win,",name,"!")
            print("You guessed the number in ", number_of_guesses," tries")
            break
        
        elif guess != values:
            #print("here")
            if guess > values:
                print("You're too high!")
                number_of_guesses+=1
            if guess < values:
                print("You're too low!")
                number_of_guesses+=1
            print("Guess again")
        if number_of_guesses >= 6:
            print("You took too many guesses, you LOSE!")
            play = False
            break
        
    #print("Would you like to play again? Enter: [y]/[n]")
    #userInput = input()
    userInput = input("Would you like to play again? Enter: [y]/[n]")
    if userInput == 'y' or userInput == 'Y':
        #keep playing
        play = True
    
    elif userInput == 'n' or userInput == 'N':
        #stop playing
        print("Here")

        play = False
        break
  