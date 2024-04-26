#!/bin/bash

if [ $# -ne 1 ]; then
    echo "No File Passed"
    exit 1
fi

filename="$1"

echo "Searching file using locate"

ans= locate "$filename" 2>/dev/null


echo "finding using find"

find / -name "$filename" 2>/dev/null