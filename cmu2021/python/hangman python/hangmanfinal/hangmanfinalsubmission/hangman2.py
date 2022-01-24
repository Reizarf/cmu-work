import random
import sys

name = input("Hey there, what's your name?")
print("Hey, " + name,"This is my first attempt at a hangman game, give it a shot!")

def print_stage(tries):
    if tries == 9:
            print('''


      
               _________
               |  _____ +
               | |      
               | |      
               | |      
               | |      
               | |
               | |
              /| |\\
 ----------------------------

                ''')
    if tries == 8:
            print('''
            


       
               _________
               |  _____ +
               | |      0
               | |      
               | |      
               | |      
               | |
               | |
              /| |\\
 ----------------------------

                ''')
    if tries == 7:
            print('''
                   
               _________
               |  _____ +
               | |      0
               | |      |
               | |      
               | |      
               | |
               | |
              /| |\\
 ----------------------------



            ''')
    if tries == 6:
            print('''
                _________
               |  _____ +
               | |      0
               | |      |
               | |      |
               | |      
               | |
               | |
              /| |\\
 ----------------------------

            ''')
    if tries == 5:
            print('''
                       
    
                _________
               |  _____ +
               | |      0
               | |     /|
               | |      |
               | |      
               | |
               | |
              /| |\\
 ----------------------------


            ''')
    if tries == 4:
                print('''
    

               _________
               |  _____ +
               | |      0
               | |     /|
               | |      |
               | |      
               | |
               | |
              /| |\\
 ----------------------------
                ''')
    if tries == 3:
                print('''
       
   
               _________
               |  _____ +
               | |      0
               | |     /|\\
               | |      |
               | |      
               | |
               | |
              /| |\\
 ----------------------------
                ''')
    if tries == 2:
                print('''
                   _________
               |  _____ +
               | |      0
               | |     /|\\
               | |      |
               | |     / 
               | |
               | |
              /| |\\
 ----------------------------
         
                ''')
    if tries == 1:
                    print('''
              
                _________
                |  _____ +
                | |      0
                | |     /|\\
                | |      |
                | |     / \\
                | |
                | |
               /| |\\
 --------------------------
                    ''')
    if tries == 0:
            print("You lost, better luck next time!")



f = open('words.txt', 'r')
content = f.read()

word = random.choice(list(open('words.txt')))

#print(word)
#opens words.txt and randomly selects a word

 
print("Guess the characters")

guesses = ''

missed = 0
tries = 10
#setting the number of predefined tries to 10
correct = 0


#print("correct count:",correct)
if word.endswith(' '):
    word = word[:-1]
word = word.strip('\n')
#print(f"DEBUG: word is: {word}----------This is the same line after the word")
#print(len(word))
#os.system("PAUSE")
#input()
while tries > 0:
    correct = 0
    
   
    print_stage(tries)
    for char in word:
        #print(f"DEBUG: char is:{char}")
        #look for user input in given word
        if char in guesses: 
            print(char)
            
            correct+=1
             
        else: 
            #missed guess
            print("_")
    
    
    guess = input("Guess just one letter")

    #print(f"DEBUG: missed is: {missed}")
    #print(f"DEBUG: The length of the word is: {len(word)}")
    #print(f"DEBUG: correct is: {correct}")
    if correct == len(word):
        #all guesses correct
        print("Congratulations!,",name,"You win!") 
         
        
        print("The word was: ", word) 
        break
    print(f"DEBUG: correct is: {correct}")
    
    guesses += guess 
    print(guesses)
    
    if guess not in word:
         
        tries -= 1
       
        print("Wrong, give it another go")
         
        print(tries)
        print("You have", + tries, 'guesses left')
        missed+=1
        if tries == 0:
            print("Game over, out of tries!")
            break


    if guesses == word:
        print("You win",name,"congratulations!")
        break

