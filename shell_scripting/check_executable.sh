#!/bin/bash

if [ $# -eq 0 ]; then
    echo "No file passed"
    exit 1
fi

file="$1"


if [ ! -e "${file}" ]; then
    echo "File does not exist"
    exit 1
fi

if [ -x "$file" ]; then
    echo "file has executable permission"
    chmod -x "$file"
    echo "Removed executablle permmision"
else
    echo "File doesnt have ppermission"
fi