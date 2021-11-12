import unittest
language_remap = {
    "A": "@",
    "B": "8",
    "C": "(",
    "D": "|)",
    "E": "3",
    "F": "#",
    "G": "6",
    "H": "[-]",
    "I": "|",
    "J": "_|",
    "K": "|<",
    "L": "1",
    "M": "[]\\/[]",
    "N": "[]\\[]",
    "O": "0",
    "P": "|D",
    "Q": "(,)",
    "R": "|Z",
    "S": "$",
    "T": "']['",
    "U": "|_|",
    "V": "\\/",
    "W": "\\/\\/",
    "X": "}{",
    "Y": "`/",
    "Z": "2"
}


def lang(s):
    o = ord(s)
    if 97 <= o <= 122:
        return language_remap[chr(o - 32)]
    if 65 <= o <= 90:
        return language_remap[s]
    return s

x = 'saveme'
#for i in input():
def saveme(x):
    for i in input():
        print(lang(i), end=' ')
assert saveme(x) == '$ @ \/ 3 []\/[] 3'


saveme()

