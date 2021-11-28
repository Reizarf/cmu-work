import random, itertools
#generate deck
deck = list(itertools.product(range(1,14),['Spade','Heart','Diamond','Club']))
#shuffle
random.shuffle(deck)

#draw top card
print("Top two cards are: ")
for i in range(2):
    print(deck[i][0], "of ",deck[i][1])

