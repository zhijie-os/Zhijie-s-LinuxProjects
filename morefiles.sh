#! /bin/bash

if [ "$#" -lt 2 ];then 
    echo    "Too few arguments"
elif [ "$#" -gt 2 ];then
    echo    "Too many arguments"
else
    Num1="$(./numfiles.sh $1|awk '{print $4}')"
    Num2="$(./numfiles.sh $2|awk '{print $4}')"
    echo "$1 has $Num1 regular files."
    echo "$2 has $Num2 regular files."

    if [ "$Num1" -gt "$Num2" ];then
        echo "$1 has more files."
    elif [ "$Num1" -lt "$Num2" ];then
        echo "$2 has more files."
    else
        echo "$1 and $2 have the same number of files."
    fi
fi