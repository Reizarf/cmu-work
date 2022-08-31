#!/usr/bin/bash




#press space on menu to select item
# CHOICES=$(whiptail --title "Check list" --notags --checklist "Choose one or more options" 15 50 5 \
#     "1)" "Print iptables:" OFF \
#     "2)" "Add rule: " OFF \
#     "3)" "Delete rule: " OFF \
#     "4)" "Insert rule: " OFF \
#     "5)" "Help" OFF 3>&2 2>&1 1>&3
#     )
# echo $CHOICES

#yes/no

if $(whiptail --title "Should we really meet/delete/whatever" --yesno \
    "Should we meet for finals? " 15 50 3>&2 2>&1 1>&3

    ); then
echo "YES"
else
echo "NO"
fi




# CHOICE=$(whiptail --title "Sample Menu" --menu "Select an option: " 15 50 5 \
#     "1)" "Print iptables:" \
#     "2)" "Add rule: " \
#     "3)" "Delete rule: " \
#     "4)" "Insert rule: " \
#     "5)" "Help" 3>&2 2>&1 1>&3
#     )

# echo "You selected:  $CHOICE"

# case $CHOICE in
#     "1)")
#         echo "you selected to print iptables: ";;
#     "2)")
#         echo "You want to add a new rule...";;
#     "3)")
#         echo "deleting a rule...";;
# esac







#loading screen stuff
# {
#     for ((i = 0; i <= 100; i+=5++)); do
#         sleep 1
#         echo $i
#     done
# } | whiptail --gauge "Please wait..." 60 50 0

