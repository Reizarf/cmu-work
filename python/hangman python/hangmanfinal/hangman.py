
import random
print("Hello World!")
# line 1 test

# This program will walk through the stages of Hangman, assuming every guess is incorrect. 
# There should be an entire body hanging, and each stage only one limb is removed. 



#Gives access or opens words.txt file


#saving file contents in content

f = open('words.txt', 'r')
content = f.read()

word = random.choice(list(open('words.txt')))
print(word)

#print(content) outputs entire list of words.txt
turns = 15


tries = 0
while tries < 10:
    tries = 0
    turns = 15
    guess = input("Guess one character!")
    for char in word:
        if char in guess:
            print(char)
        else:
            print("_")
            tries+=1
    guess = input("Guess one character!")
    if turns == 0:
        print("User wins!")
        print("the word is", word)
        break


    if guess not in word:
        turns -=1
        print("Wrong guess, try again!")
        print("You have",turns,"guesses left! Don't guess wrong!")
        tries+=1
    
    if turns == 0:
        tries+=1
        print("Game over! Out of tries")

        
#output the selected randomly chosen word in words.txt

# #str(word)
# def count(word):
#     result = 0
#     for char in word:
#         result+=1
#     # return result
# # print(count(word))

























# str1 = ("""
#               _________
#               |  _____ +
#               | |      0
#               | |     /|\\
#               | |      |
#               | |     / \\
#               | |
#               | |
#              /| |\\
# ----------------------------
# """)

# print(str1 + "\n" + "Stage 0" + "\n")

# str2 = ("""
#               _________
#               |  _____ +
#               | |      0
#               | |     /|\\
#               | |      |
#               | |     / 
#               | |
#               | |
#              /| |\\
# ----------------------------
# """)

# print(str2 + "Stage 1" + "\n")

# str3 = ("""
#               _________
#               |  _____ +
#               | |      0
#               | |     /|\\
#               | |      |
#               | |      
#               | |
#               | |
#              /| |\\
# ----------------------------
# """)

# print(str3 + "Stage 2" + "\n")

# str4 = ("""
#               _________
#               |  _____ +
#               | |      0
#               | |     /|
#               | |      |
#               | |      
#               | |
#               | |
#              /| |\\
# ----------------------------
# """)
# print(str4 + "Stage 3" + "\n")

# str5 = ("""
#               _________
#               |  _____ +
#               | |      0
#               | |     /|
#               | |      |
#               | |      
#               | |
#               | |
#              /| |\\
# ----------------------------
# """)
# print(str5 + "Stage 4" + "\n")
# str6 = ("""
#               _________
#               |  _____ +
#               | |      0
#               | |      |
#               | |      |
#               | |      
#               | |
#               | |
#              /| |\\
# ----------------------------
# """)
# print(str6 +"Stage 5" + "\n")

# str7 = ("""
#               _________
#               |  _____ +
#               | |      
#               | |     
#               | |      
#               | |      
#               | |
#               | |
#              /| |\\
# ----------------------------
# """)

# print(str7 + "Stage 6" + "\n")
# print("Game over!")