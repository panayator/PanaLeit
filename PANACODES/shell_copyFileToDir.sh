#!/bin/bash

if [ $# -ne 2 ]
then
  echo "Too few arguments! Try bash /home/path/to/directory/shell.sh file.txt folder"
else
  if [ ! -d $2 ]
  then
    echo "Directory doesn't exist."
    echo "Directory created."
    mkdir $2
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
