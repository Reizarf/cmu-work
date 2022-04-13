#! /bin/bash
#set -x

numberOne(){
    echo "You are here"
    pwd
    echo ""
    echo "These are the contents of the current directory."
    ls -la
    echo ""
    echo "Would you like to go up one directory? {[u] Up}: "
    echo "Or to enter a directory, type: \"cd\" "
    echo "If you'd like to use wc, type \"wc\" "
    read input
    while [[ true ]]; do
        if [[ $input == 'wc' ]]; then
            wcFunc
        fi
        if [[ $input == 'u' ]]; then
            cd ..
            echo "You are now here..."
            numberOne
        fi
        if [[ $input == 'cd' ]]; then
            echo "Enter the directory you'd like to go into: "
            read directory
            cd $directory
            #wcFunc #FIXME
        fi
            numberOne
        
        #wc *
    done

    #system(clear) //clear the screen after???
}
wcFunc(){
    echo "Enter which option: "
    echo "-c: bytes"
    echo "-m: chararacters"
    echo "-l: lines"
    echo "-w: word count"
    read input
    if [[ $input == '-c' ]]; then
        echo "Enter which file you'd like to use -c on: "
        read file
        wc -c $file
    fi
    if [[ $input == '-m' ]]; then
        echo "Enter which file you'd like to use -m on: "
        read file
        wc -m $file
    fi
    if [[ $input == '-l' ]]; then
        echo "Enter which file you'd like to use -l on: "
        read file
        wc -l $file
    fi
    if [[ $input == '-w' ]]; then
        echo "Enter which file you'd like to use -w on: "
        read file
        echo "wordcount="
        wc -w $file
        echo $wordcount
    fi
}



makeDemFiles(){
    echo "set your prefix: " ##set filename
    read prefix
    echo "how many files: "
    read newcount
    number=1                            # start number
    ext="txt"                           # file extension to add

    printf -v num "%03d" "$number"      # create 3-digit start number
    fname="$prefix$num.$ext"            # form first filename

    while [ -e "$fname" ]; do           ## while filename exists
        number=$((number + 1))            ## increment number
        printf -v num "%03d" "$number"    ## form 3-digit number
        fname="$prefix$num.$ext"          ## form filename
    done

    while ((newcount--)); do            ## loop newcount times
        touch "$fname"                    ## create filename
        ((! newcount)) && break;          ## newcount 0, break (optional)
        number=$((number + 1))            ## increment number
        printf -v num "%03d" "$number"    ## form 3-digit number
        fname="$prefix$num.$ext"          ## form filename
    done
}

randomNumberGuesser(){
    
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
    echo "Enter a number between 1 and 20: "
    read guess
    checkNumber p $guesses
done

}

while [[ true ]]; do
    echo "
    Options...
    1) Print current directory and files
    2) Number Guessing Game
    3) Create 10 files:
    4) Date display manipulation
    ...
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
