#!bin/bash

# How to use it :
# sh set_header.c "*.X" or "directory/*.c"
# With .X being the file extension you wanna modify. DO NOT FORGET THE QUOTES!
# Only works for the current directory if not specified

if [ "$#" -ne 1 ]; then
	  echo "Usage:  sh set_header.sh \"*.c\"" >&2
	    exit 1
	fi

ls $1 > file_to_change
DATA=`cat file_to_change`
for FILE in $DATA
do
	VALUE=$(grep "//*" $FILE | head -11 | wc -l | tr -d ' ')
	if [ $VALUE = "11" ]; then
		vim $FILE -c "d12" -c "Stdheader" -c "wq"
		echo "$FILE : have a header !"
	else
		echo "$FILE : haven't a header !"
		vim $FILE -c "Stdheader" -c "wq"
	fi
done;

rm -f file_to_change
