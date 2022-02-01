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
}

cleanUp(){
    echo "----------------"
    echo "---Cleaning.----"
    echo "----------------"

    sudo apt-get autoremove -yy
    sudo apt-get autoclean
}

finish() {
    echo "--------------------"
    echo "--Update Complete!--"
    echo "-----------------"
    exit
}

# menu-help(){
#     cat << _EOF_

#     Text.

#     _EOF_

# }



if [ "$1" == "--disk" ]; then
    updateSystem
    cleanUp
    finish
fi
