#!/bin/bash

read -p "Enter three numbers: " a b c

if [ $a -lt $b ]; then
    if [ $a -lt $c ]; then
        echo "$a"
    else 
        echo "$c"
    fi
else
    if [ $b -lt $c ]; then
        echo "$b"
    else 
        echo "$c"
    fi
fi
