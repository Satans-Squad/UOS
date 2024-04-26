#!/bin/bash

echo "printing top 10 commands using history"
history | head -n 10

echo "Generating frequency list of used commands"
cat ~/.bash_history | awk '{print $1}' | sort | uniq -c | sort -nr | head -n 5
cat ~/.bash_history | awk '{print $1}' | sort | uniq -c | sort -nr | head -n 5


# cat ~/.bash_history | awk '{print $1}'  | uniq -c | sort -nr | head -n 5
























