#!/usr/bin/env bash

read -p "enter the number: " n
((n++))

while [[ 1 ]]; do
    is_prime=1
    x=2
    while [[ $x -lt $n ]]; do
        rem=$(( n%x ))
        if [[ $rem -eq 0 ]]; then
            is_prime=0
            break
        fi
        ((x++))
    done
    rev=""
    tmp=$n
    while [[ $tmp -gt 0 ]]; do
        rem=$(( tmp%10 ))
        rev="$rev$rem"
        (( tmp /= 10))
    done
    if [[ $is_prime -eq 1 ]] && [[ $rev -eq $n ]]; then
        echo "$n"
        exit 0
    fi
    ((n++))
done

