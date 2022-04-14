#! /bin/bash
#set -x

source bashFunctions.sh
. ./bashFunctions.sh

menu(){
    while [[ true ]]; do
    echo "
    Options...
    1) Print current directory and files (wc)
    2) Number Guessing Game
    3) Create 10 files: (w/ prefix)
    4) Date display manipulation
    
    0. Exit
    "
    read -p "Enter Selection [0-9]: "
    clear

    if [[ $REPLY =~ ^[0-9]$ ]]; then
        if [[ $REPLY == 1 ]]; then
            #show the number of files in a given directory (wc)
            #function should prompt for a directory or a list of
            #directories to run the command on
            numberOne
            echo "here"
        fi
        if [[ $REPLY == 2 ]]; then
            #4: Play the numer guessing game
            #similar to in class
            
            randomNumberGuesser
        fi
        if [[ $REPLY == 3 ]]; then
            #6: create 10 files in a specific directory
            #with a specified prefix (with a number after the prefix)
            makeDemFiles
        fi
        if [[ $REPLY == 4 ]]; then
            #7: manipulate the date display
            #7b: (MM/DD/YY) and (HH:MM:SS) and (YYYY/MM/DD)
            # or display epoch seconds
            echo "here"
            dateFunction
        fi
        if [[ $REPLY == 5 ]]; then
            echo "here"
        fi
        if [[ $REPLY == 6 ]]; then
            #ifconfig
            echo "here"
        fi
        if [[ $REPLY == 7 ]]; then
            #hostname
            echo "here"
        fi
        if [[ $REPLY == 0 ]]; then
            exit
        fi
        
    else
        echo "Try another entry"
    fi
    read -p "Enter to continue: "
    clear
done
}
menu #run the program