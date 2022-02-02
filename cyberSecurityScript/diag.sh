#! /usr/bin/bash
#https://youtube.com/watch?v=_n5ZegzieSQ
set -e

#Functions :

updateSystem() {

    echo "-----------------"
    echo "-Updating System-"
    echo "-----------------"
    #work
    sudo apt-get update
    sudo apt-get upgrade
    finish
    exit
}

cleanUp(){
    echo "----------------"
    echo "---Cleaning.----"
    echo "----------------"
    #work
    sudo apt-get autoremove -yy
    sudo apt-get autoclean
    finish
    exit
}

checkDate(){
    echo "--------------------------"
    echo "-The current date/time is:-"
    #work
    date
    echo "--------------------------"
    finish
    exit
}

finish() {
    echo "------------------------------------------------"
    echo "----------------Work Complete!------------------"
    echo "------------------------------------------------"
    exit
}

menu-help(){
#     cat << _EOF_

#     Text.

#     __EOF__
    echo "------------------------------------------------"
    echo "---------------------MENU-----------------------"
    echo "--update: Runs update and upgrade"
    echo "--clean: Runs cleaning procedures"
    echo "--help: Display's this help menu"
    echo "--date: Diplay current date/time on the machine"
}


if [ "$1" == "--date" ]; then
    checkDate
    finish
fi

if [ "$1" == "--update" ]; then
    updateSystem
    #cleanUp
    finish
fi

if [ "$1" == "--clean" ]; then
    cleanUp
    
    finish
fi


if [ "$1" == "--help" ]; then
    menu-help
    finish
fi

