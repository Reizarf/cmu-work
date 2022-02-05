#! /usr/bin/bash
#https://youtube.com/watch?v=_n5ZegzieSQ

# %%bash

# # print line and total characters in each line for contents of home dir
# count=1
# for i in $(ls ~); do
#     echo "Line $count ($i) contains $(echo -n $i | wc -c) characters"
#     (( count++ ))
# done
# From Basnet : will list number of characters in each file

#If no command is given the menu should pop up, check out basnet's menu script
#follow his menu structure


#Functions :



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

while [[ true ]]; do
    echo "
    1.) Update & Clean the system
    2.) Check the system's version
    3.) Count files and folders in given directory
    4.) Check system's date config
    5.) Evaluate space at /home/
    6.) Check system's IP connection
    "
    read -a "Enter Selection [0-6]: "
    clear
    if [[ $REPLY =~ ^[0-6]$ ]]; then
        # if [[ $REPLY == 0]]; then
        #     echo "Program ended. Goodbye!..."
        #     exit 0
        # fi
        if [[ $REPLY == 1 ]]; then
            systemMaitenance
        fi
        
        if [[ $REPLY == 2 ]]; then
            versionCheck
        fi
        
        if [[ $REPLY == 3 ]]; then
            filesAndFolders
        fi

        if [[ $REPLY == 4 ]]; then
            checkDate
        fi

        # if [[ $REPLY == 5 ]]; then
        #     #write function
        # fi

        if [[ $REPLY == 6 ]]; then
            checkIP
        fi
    else
        echo "Try another entry..."
    fi
    read -a 
    echo "Enter to continue"
done
