#! /bin/bash
Counter=0

for Byte in $(ls -l|grep "^-"|awk ' {print $5} ')
do
    Counter=$((Counter+Byte)) 
done

echo "The total number of bytes is : $Counter"

