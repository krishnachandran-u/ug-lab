read -p "Enter the password: " pass

if [[ ${#pass} -ge 8 ]] && [[ $pass =~ [a-z] ]]  && [[ $pass =~ [A-Z] ]] && [[ $pass =~ [0-9] ]] && [[ $pass =~ [_] ]]; then
    echo "Strong Password"
else 
    echo "Weak Password"
fi


