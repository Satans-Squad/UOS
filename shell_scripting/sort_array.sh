#!/bin/bash

numbers=(1 2 4 6 2 1 49 28 29 30 0)

# sorted_numbers=($(echo "${numbers[@]}" | tr ' ' '\n' | sort -n))

ans=($(echo "${numbers[@]}" | tr ' ' '\n' | sort -n))

echo "Sorted Array is:"

# for num in "${ans[@]}"; do
#     echo "${num}"

# done

echo "${ans[@]}"