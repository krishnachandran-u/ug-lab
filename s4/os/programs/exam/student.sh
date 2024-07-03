#!/usr/bin/env bash

read -p "Enter the filname: " filename

while IFS= read -r line; do
    cur=($line)
    m1=${cur[1]} 
    m2=${cur[2]} 
    m3=${cur[3]} 
    if [[ $m1 -ge 50 ]] && [[ $m2 -ge 50 ]] && [[ $m3 -ge 50 ]]; then
        echo "${cur[0]} passed"
    else 
        echo "${cur[0]} failed"
    fi
done < $filename
