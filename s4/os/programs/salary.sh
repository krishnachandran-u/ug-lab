echo "enter Salary"
read basicSalary
grossSalary=0
HRA=0
DA=0
if [ $basicSalary -lt 1500 ]
then
	HRA=$((1*$basicSalary/100))
	DA=$((9*$basicSalary/100))
else
	HRA=500
	DA=$((98*$basicSalary/100))
fi
grossSalary=$(($basicSalary + $HRA + $DA))
echo $grossSalary

