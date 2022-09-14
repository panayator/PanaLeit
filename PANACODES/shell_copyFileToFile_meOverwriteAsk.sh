#!/bin/bash

if [ $# -ne 2 ]
then
  echo "Too few arguments! Try bash /home/path/to/directory/shell.sh file1.txt file2.txt"
else
	if [ ! -f $1 ]
	then
		echo "File doesn't exist."
		echo "File created."
		touch $2
	
  	fi
 	
  	if [ ! -f $2 ]
  	then
    		echo "File doesn't exist."
    		echo "File created."
    		touch $1
    	elif [ -f $2 ]
	then
  		echo "File exists. Do you want to overwrite it? Type y (Yes) or n (No)"
  		read answer
  		if [ $answer = y ]
		then
 			cp $1 $2
   			echo "Done. $1 has been copied to $2"
   			exit
   		elif [ $answer = n ]
   		then
   			exit
  		fi
  	fi
  	
fi
