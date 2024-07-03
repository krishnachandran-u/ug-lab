#!/bin/bash

read -p "Enter number 1 :" n1
read -p "Enter number 2 :" n2

for (( i=$n1 ; i<=$n2 ; i++ ))
do
   s=0
   a=$i
   l=${#a}
   while [ $a -gt 0 ]
   do
       k=$((a%10))
       s=$((k**l+s))
       a=$((a/10))
   done
   if [ $s -eq $i ]
   then
       echo $i
   fi
done
