numberOne(){
    echo "You are here"
    pwd
    echo ""
    echo "These are the contents of the current directory."
    ls -a
    echo ""
    echo "Would you like to go up one directory? {[u] Up}: "
    echo ""
    echo "Or to enter a directory, type: \"cd\" "
    echo ""
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
    
    echo ""
    echo "Number of files in directory: "
    ls | wc -w
    echo ""
    
    echo "Enter which option: "
    echo "-c: bytes"
    echo "-m: chararacters"
    echo "-l: lines"
    echo "-w: word count"

    

    read input
    if [[ $input == '-c' ]]; then
        echo "Enter which file you'd like to use -c on: "
        read file
        clear
        echo "======================"
        echo "Byte Count: "
        wc -c $file
        echo "======================"
    fi
    if [[ $input == '-m' ]]; then
        echo "Enter which file you'd like to use -m on: "
        read file
        clear
        echo "======================"
        echo "Character count: "
        echo ""
        wc -m $file
        echo "======================"
    fi
    if [[ $input == '-l' ]]; then
        echo "Enter which file you'd like to use -l on: "
        read file
        clear
        echo "======================"
        echo "Line count: "
        echo ""
        wc -l $file
        echo "======================"
    fi
    if [[ $input == '-w' ]]; then
        echo "Enter which file you'd like to use -w on: "
        read file
        clear
        echo "======================"
        echo "Wordcount: "
        echo ""
        wc -w $file
        echo "======================"
        #echo $wordcount
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

    while [ -e "$fname" ]; do           # while filename exists
        number=$((number + 1))            # number++
        printf -v num "%03d" "$number"    # create 3-digit
        fname="$prefix$num.$ext"          # form the filename
    done

    while ((newcount--)); do            # loop newcount times
        touch "$fname"                    # create filename
        ((! newcount)) && break;          # break(optional)
        number=$((number + 1))            # number++
        printf -v num "%03d" "$number"    # create 3-digit
        fname="$prefix$num.$ext"          # form the filename
    done
}

randomNumberGuesser(){
    rando=$(( $RANDOM % 20 ))
    #echo "rando: $rando"
    function checkNumber() {
        if [[ $rando -eq $guess ]]
        then
            echo "You guessed the number in $guesses guesses!"
            #exit 0
            menu
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





dateFunction(){

    echo "Select which format: "
    echo "1) (YYYY/MM/DD)"
    echo "2) (HH:MM:SS)"
    echo "3) (MM/DD/YY)"
    echo "4) Epoch time"
    echo "5) 12 hour format clock"
    echo "6) 24 hour format clock"
    echo "7) Display both date and time"
    echo "8) Bonus: What was yesterday?"
    echo "9) Bonus: What's tomorrow?"
    echo "0) EXIT"
    
    while [[ 1 ]]; do
        read input
        if [[ $input == "1" ]];
        then
            first
        elif [[ $input == "2" ]];
        then
            second
        elif [[ $input == "3" ]];
        then
            third
        elif [[ $input == "4" ]];
        then
            fourth
        elif [[ $input == "5" ]];
        then
            fifth
        elif [[ $input == "6" ]];
        then
            sixth
        elif [[ $input == "7" ]];
        then
            seven
        elif [[ $input == "8" ]];
        then
            bonus1
        elif [[ $input == "9" ]];
        then
            bonus2
        elif [[ $input == "0" ]];
        then
            #zero
            menu
        else
            echo "Try again!"
        fi;

        
    done
    

    

}


first(){
        date +%Y/%m/%d
        #YYYY/MM/DD
    }
second(){
        echo "h:m:s"
        date +%H:%M:%S:
        #HH:MM:SS
    }
third(){
        #MM/DD/YY
        date +%D
    }
fourth(){
        echo "Seconds since January 1st 1970: "
        date +%s
    }
fifth(){
        #12 hour format clock
        date +%r
    }
sixth(){
        #24 hour format clock
        date +%T
    }
seven(){
        #display both date and time
        date +%F%r
    }
bonus1(){
        echo "Yeserday's date is: "
        date --date "yesterday"
    }
bonus2(){
        echo "Tomorrows date is: "
        date --date "tomorrow"
    }
zero(){
    exit
}