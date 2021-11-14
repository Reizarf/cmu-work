#! /usr/bin/env python3
# https://open.kattis.com/problems/fizzbuzz2

__author__ = "Jacob Hansen"
__license__ = "MIT"
__copyright__ = "Copyright 2021"

import sys

def fizzBuzz(num):
    answer = ""
    for i in range(1, num + 1):
        if i % 3 == 0 and i % 5 == 0:
            answer += "fizzbuzz "
        elif i % 3 == 0:
            answer += "fizz "
        elif i % 5 == 0:
            answer += "buzz "
        else:
            answer += str(i) + " "
    answer.strip()
    return answer

def check(answer, input):
    answerArray = answer.split()
    inputArray = input.split()
    counter = 0
    numCorrect = 0
    for index in inputArray:
        if answerArray[counter].strip() == index.strip():
            numCorrect += 1
        counter += 1
    return numCorrect

def compare(length, responses):
    bestResponse = 0
    bestEmployee = None
    expected = fizzBuzz(length)
    for submission in responses:
        numCorrect = check(expected, submission)
        if bestEmployee != None:
            if numCorrect > bestResponse:
                bestEmployee = responses.index(submission)
                bestResponse = numCorrect
        else:
            bestEmployee = responses.index(submission)
            bestResponse = numCorrect
    return bestEmployee

def solve():
    responses = []
    data = sys.stdin.readline()
    dataSplit = data.split()
    employees = int(dataSplit[0])
    length = int(dataSplit[-1])
    for i in range(employees):
        line = sys.stdin.readline()
        responses.append(line.strip())
    answer = compare(length, responses)
    print(answer)

if __name__ == "__main__":
    #solve()
    print(check("1 2 fizz 4 buzz ", "1 2 fizz 4 buzz "))