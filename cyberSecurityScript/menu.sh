#! /usr/bin/bash

#Functions:
systemMaitenance() {
    
    echo "-----------------"
    echo "-Updating System-"
    echo "-----------------"
    #work
    sudo apt-get update &#update
    sudo apt-get upgrade &#upgrade
    
    sudo apt-get autoremove -yy #cleaning
    sudo apt-get autoclean
    
    finish
    exit
}

versionCheck(){
    echo "Finding system's OS and version..."
    cat /etc/os-release
}

online(){
    uptime
}

checkDate(){
    echo "--------------------------"
    echo "-The current date/time is:-"
    #work
    date
    echo "--------------------------"
}

systemDiskSpace() {
    echo "Disk space Utilization: "
    df -h
}

ipInfo() {
    ifconfig
}


while [[ true ]]; do
    echo "
    1.) Update & Clean the system
    2.) Check the system's version
    3.) Show system UpTime
    4.) Check system's date config
    5.) Evaluate space at /home/
    6.) Check system's IP connection
    "
    read -p "Enter Selection [0-6]: "
    clear

    if [[ $REPLY =~ ^[0-6]$ ]]; then
        if [[ $REPLY == 1 ]]; then
            systemMaitenance
        fi
        if [[ $REPLY == 2 ]]; then
            versionCheck
        fi
        if [[ $REPLY == 3 ]]; then
            online
            #this isn't working as planned
        fi
        if [[ $REPLY == 4 ]]; then
            checkDate
        fi
        if [[ $REPLY == 5 ]]; then
            # check space at home function
            systemDiskSpace
        fi
        if [[ $REPLY == 6 ]]; then
            #ifconfig
            ipInfo
        fi
    else
        echo "Try another entry"
    fi
    read -p "Enter to continue: "
    clear
done
