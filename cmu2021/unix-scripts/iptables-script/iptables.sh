printMenu() {
    echo "1) ADD a rule: "
    echo "2) DELETE a rule: "
    echo "3) MODIFY a rule: "
    echo "4) PRINT rules: "
    echo "5) Help "
    echo "6) Exit "

}
printHelp() {
    echo "1) - ADDING A RULE - "
    echo " Adds a rule to the specified chain. "

    echo "2) - DELETING A RULE - "
    echo " deletes/removes a rule to the specified chain. "

    echo "3) - MODIFYING A RULE - "
    echo " Changes properties of a rule within the specified chain. "

    echo "4) - PRINTING A RULE - "
    echo " Print's this help menu! - "

    echo "5) Exit - Exits the program! Duh!"
}

printChains() {
    echo "1) Input: "
    echo "2) Output: "
    echo "3) Forwarding: "
}

addRule() {
    echo "Enter the chain...: " 
    read chain
    echo "Enter the rule...:" 
    read rule
    echo "Adding rule to $chain....!"
    iptables -A $chain $rule
    echo "Done!"
    sudo iptables -L
}

deleteRule() {
    echo "Enter the chain: " 
    read chain
    echo "Enter the rule: " 
    read rule
    if iptables -C $chain $rule; then
        echo "Rule found! -"
        echo "Are you sure you want to remove this rule? (Yy/Nn)"
        read reply
        if [ $reply = "y" ]; then
            echo "Deleting the rule from $chain"
            iptables -D $chain $rule
            else
                echo "Rule not deleted"
        fi
    fi
}

modifyRule() {
    echo "Enter the chain: " read chain
    echo "Enter the rule: " read rule
    if iptables -C $chain $rule; then
        echo "Rule found"
        echo "Are you sure you want to remove this rule? (Yy/Nn)"
        read reply
        if [ $reply = "y" ]; then
            echo "Modifying the rule from $chain"
            iptables -D $chain $rule
            iptables -A $chain $rule
            else
            echo "Rule not found"
        fi
    else
        echo "rule not found.. try again"
    fi
}

printRules() {
    echo "Enter the chain you want to print the rules from: "
    read chain
    if [ $chain == "INPUT" ]; then
        iptables -L INPUT
    
    elif [ $chain == "OUTPUT"]; then
        iptables -L OUTPUT
    elif [ $chain == "FORWARDING"]; then
        iptables -L FORWARDING
    else
        echo "invalid"
    fi

}

# MAIN
while true; do
    printMenu
    read choice
    case $choice in
        1)addRule ;;
        2) deleteRule ;;
        3) modifyRule ;;
        4) printRules ;;
        5) printHelp ;;
        6) exit ;;
        *) echo "invalid" ;;
    esac done