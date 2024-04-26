#!/bin/bash

if [ $# -ne 1 ]; then
    echo "No File name passed"
    exit 1
fi 

filename="$1"

if [ -e "$filename" ]; then
    echo "File Exist on the drive"
    ls -l "$filename"
else
    echo "File Does not exist on drive"
    exit 1  # Terminates the script
fi

pwd  # This line will not be executed if exit 1 is called earlier
