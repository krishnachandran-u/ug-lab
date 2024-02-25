#!/bin/bash

read -p "Enter the lower bound: " l
read -p "Enter the upper bound: " r

power() {
    local result=1
    local base=$1
    local exponent=$2

    for ((i = 1; i <= exponent; i++)); do
        ((result *= base))
    done

    echo $result 
}

for i in $(seq "$l" "$r"); do
    sum=0
    k=$i
    len=0

    while [[ $k -gt 0 ]]; do
        ((len += 1))
        ((k /= 10))
    done

    k=$i

    while [[ $k -gt 0 ]]; do
        ((sum += $(power $((k % 10)) $len)))
        ((k /= 10))
    done

    if [ $i -eq $sum ]; then
        echo $i
    fi
done

