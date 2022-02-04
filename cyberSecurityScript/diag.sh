#! /usr/bin/bash
#https://youtube.com/watch?v=_n5ZegzieSQ

#Functions :

systemMaitenance() {

    echo "-----------------"
    echo "-Updating System-"
    echo "-----------------"
    #work
    sudo apt-get update &
    sudo apt-get upgrade &

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
    
    exit
}

checkIP(){
    ifconfig
}

menu-help(){
    echo "------------------------------------------------"
    echo "---------------------MENU-----------------------"
    echo "--update: Runs update and upgrade"
    
    echo "--help: Display's this help menu"
    echo "--date: Diplay current date/time on the machine"
    echo "--file: Display # of files & folders in CWD"
    echo "--v: Display systems OS and version"
}

filesAndFolders(){
    if [ -d "$@"]; then
    echo "Files found: $(find "$direc" -type f | wc -l)"
    echo "Folders found: $(find "$direc" -type d | wc -l)"
    else
    echo "[ERROR]"
    # exit 1
fi
}
versionCheck(){
    echo "Finding system's OS and version..."
    cat /etc/os-release
}

if [ "$1" == "--date" ]; then
    checkDate
fi

if [ "$1" == "--update" ]; then
    systemMaitenance
fi

if [ "$1" == "--clean" ]; then
    cleanUp
fi

if [ "$1" == "--file" ]; then
    echo "Enter the path you'd like to evaluate: "
    read direc
    echo "you picked: $direc"

    filesAndFolders
fi

if [ "$1" == "--help" ]; then
    menu-help
fi

if [ "$1" == "--v" ]; then
    versionCheck
fi
