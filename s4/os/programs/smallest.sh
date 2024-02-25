echo "Enter three numbers"
read a
read b
read c
if [ $a -lt $b ] && [ $a -lt $c ] 
then 
    echo $a
elif [ $b -lt $a ] && [ $b -lt $c ] 
then 
    echo $b
else 
    echo $c 
fi

