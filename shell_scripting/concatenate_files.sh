#!/bin/bash

# Check if the number of arguments is less than 2
if [ "$#" -lt 1 ]; then
    echo "Error: You need to provide at least two filenames."
    exit 1
fi

# Check if all files exist
for file in "$@"; do
    if [ ! -f "$file" ]; then
        echo "Error: File '$file' does not exist."
        exit 1
    fi
done

# Concatenate files
cat "$@" > "output.txt"
