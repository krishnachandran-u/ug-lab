#!/bin/bash

read -p "Enter the number of arguments: " num

names=()
for (( i=0; i<num; i++ )); do
    read -p "Enter element $i : " x
    names+=("$x")
done 

for (( i=$num - 1; i>=0; i-- )); do
    echo "${names[$i]} "
done
