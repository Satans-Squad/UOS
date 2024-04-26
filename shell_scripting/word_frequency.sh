#!/bin/bash

echo "Fetching data from file"

tr '[:upper:]' '[:lower:]' < wonderland.txt | sort | uniq -c | sort -nr

echo "without case sensitive"
sort wonderland.txt | uniq -c | sort -nr
