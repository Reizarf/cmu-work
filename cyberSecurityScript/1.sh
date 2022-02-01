#! /usr/bin/bash
echo "What is your name?"

read name

if [$name]; then
    echo "$name Sounds alright to me"
else
    echo "I didn't hear a whole lot"
fi

