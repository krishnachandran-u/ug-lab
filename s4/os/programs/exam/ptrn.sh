#!/usr/bin/env bash

read -p "enter the number: " n

hf=$((n/2))

for (( i=1; i<=hf; i++ )); do
    for (( j=1; j<=$((2*i-1)); j++));do
        echo -n "*"
    done
    echo
done 

if [[ $((n%2)) == 1 ]]; then
    ((hf++))
fi
for (( i=hf; i>0; i-- )); do
    for (( j=1; j<=$((2*i-1)); j++));do
        echo -n "*"
    done
    echo
done 
