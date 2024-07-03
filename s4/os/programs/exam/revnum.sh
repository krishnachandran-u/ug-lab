#!/bin/bash

read -p "Enter the number: " a

r=0

while [[ a -gt 0 ]]; do
    r=$(( (r*10) + (a%10) ))
    a=$(( a / 10)) 
done

echo "$r"

