#!/usr/bin/bash
#set -x

rando=$(( $RANDOM % 20 ))

#echo "rando: $rando"
function checkNumber() {
    if [[ $rando -eq $guess ]]
    then
        echo "You guessed the number in $guesses guesses!"
        exit 0
    else
        if [[ $guess -lt $rando ]]
        then
            echo "Your guess is too low"
            #echo "guess: "$guess
        else
            echo "Your guess is too high"
            #echo "guess: "$guess
        fi
        echo "Try again!"
        (( guesses = $guesses + 1 ))
    fi
}
while [[ 1 ]]
do
    #echo "Enter a number between 1 and 20: "
    read guess
    checkNumber p $guesses
done
