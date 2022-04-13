#! /bin/bash
#set -x

while [[ true ]]; do
    echo "
    Options...
    1
    2
    3
    ...
    0. Exit
    "
    read -p "Enter Selection [0-9]: "
    clear

    if [[ $REPLY =~ ^[0-9]$ ]]; then
        if [[ $REPLY == 1 ]]; then
            #
            echo "here"
        fi
        if [[ $REPLY == 2 ]]; then
            #
            echo "here"
        fi
        if [[ $REPLY == 3 ]]; then
            #this isn't working as planned
            echo "here"
        fi
        if [[ $REPLY == 4 ]]; then
            #checkDate
            echo "here"
        fi
        if [[ $REPLY == 5 ]]; then
            # check space at home function
            #systemDiskSpace
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
