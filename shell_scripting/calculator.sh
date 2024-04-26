#!/bin/bash

while true; do
    echo "Welcome to Simple Calculator"
    echo "Available operations: +, -, *, /"
    
    read -p "Enter first number: " num1
    read -p "Enter second number: " num2
    read -p "Enter operation (+, -, *, /) or type 'exit' to quit: " operation

    case $operation in
        "+")
            result=$((num1 + num2))
            ;;
        "-")
            result=$((num1 - num2))
            ;;
        "*")
            result=$((num1 * num2))
            ;;
        "/")
            if [ $num2 -eq 0 ]; then
                echo "Error: Division by zero!"
                continue
            else
                result=$(echo "scale=2; $num1 / $num2" | bc)
            fi
            ;;
        "exit")
            echo "Exiting..."
            break
            ;;
        *)
            echo "Invalid operation"
            continue
            ;;
    esac

    echo "Result: $result"
done
