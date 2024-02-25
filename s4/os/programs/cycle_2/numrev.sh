#!/bin/bash

str=""

read a
while [[ $a -gt 0 ]] 
do
	str+="$(($a % 10))"
	((a/=10))
done
echo $str
