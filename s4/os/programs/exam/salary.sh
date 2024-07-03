#!/bin/bash

read -p "Enter your salary: " basic

if [ $basic -lt 1500 ]; then
    HRA=$(echo "scale=2; $basic / 10" | bc)
    DA=$(echo "scale=2; $basic*9 / 10" | bc)
else
    HRA=500
    DA=$(echo "scale=2; $basic*98 / 100" | bc)
fi

echo "HRA = $HRA; DA = $DA"
