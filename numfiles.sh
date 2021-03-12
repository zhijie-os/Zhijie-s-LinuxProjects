#! /bin/bash
COUNTER=0
FILES="$(ls $1)"
#FILES=$(ls /etc)
for FILE in $FILES
    do
        if [ ! -d "$FILE" ]
        then    
            #echo "The file name is $FILE"
            ((COUNTER++))
        fi
done

echo "There are total $COUNTER regular files in the directory"