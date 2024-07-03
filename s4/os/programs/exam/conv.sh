#!/usr/bin/env bash

read -p "Enter the number: " n

len=${#n}

x=$n
b=""

while [[ $x -gt 0 ]]; do
    rem=$((x%2))
    b="$rem$b"
    ((x /= 2))
done

echo "Binary: $b"

x=$n
d=""

while [[ $x -gt 0 ]]; do
    rem=$((x%16))
    case $rem in
        10) rem="A";;
        11) rem="B";;
        12) rem="C";;
        13) rem="D";;
        14) rem="E";;
        15) rem="F";;
    esac
    d="$rem$d"
    ((x /= 16))
done

echo "Hex: $d"
