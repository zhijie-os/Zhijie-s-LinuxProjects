#! /bin/bash

# shell script is space senstive

if [ $# -lt 2 ]
then
    echo "Too few arguments"
elif [ $# -gt 3 ]
then
    echo "Too many arguments"
else
    SIZE1="$(ls -l $1|awk '{print $5} ')"
    SIZE2="$(ls -l $2|awk '{print $5} ')"

    echo $SIZE1 $SIZE2
    if [ $SIZE1 -gt $SIZE2 ]
    then 
        echo "$1 is larger."
    elif [ $SIZE1 -lt $SIZE2 ]
    then
        echo "$2 is larger."
    else
        echo "$1 has the same size as $2"
    fi
fi