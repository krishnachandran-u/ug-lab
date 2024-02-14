echo "Enter three numbers"
read a
read b
read c
if [ $a -gt $b ] && [ $a -gt $c ] 
then 
	echo $a
elif [ $b -gt $a ] && [ $b -gt $c ] 
then 
	echo $b
else 
	echo $c 
fi

