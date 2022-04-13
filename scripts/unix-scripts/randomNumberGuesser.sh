#!/usr/bin/bash
set -x
(( random_number = $RANDOM20 + 1 ))

function checkNumber() {
    if [[ $random_number -eq $1 ]]
    then
        echo "You gyessed the number in $guesses guesses!"
    else
        echo "Try again!"
        (( guesses = $guesses + 1 ))
    fi
}
while [[ 1 ]]
do
    read -p "Enter a number between 1 and 20: " $guesses
    check_number $guesses
done
