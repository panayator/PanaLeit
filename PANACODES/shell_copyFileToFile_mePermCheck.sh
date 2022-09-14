#!/bin/bash

if [ $# -ne 2 ]
then
  echo "Too few arguments! Try bash /home/path/to/directory/shell.sh file1.txt file2.txt"
else
	if [ ! -f $2 ]
	then
		echo "File doesn't exist."
		echo "File created."
		touch $2
	elif [ -f $2 ]
	then
  		echo "File exists. Checking for write permissions..."
  		if [ -w $2 ]
		then
 			W="Can write to file" || W="Cannot write to file"
 			echo $W
  		fi
  	fi
 	
  	if [ ! -f $1 ]
  	then
    		echo "File doesn't exist."
    		echo "File created."
    		touch $1
  	fi
  	cp $1 $2
   	echo "Done. $1 has been copied to $2"
fi
