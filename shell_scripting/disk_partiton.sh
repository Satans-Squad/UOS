#!/bin/bash

# Display header
printf "%-20s %-15s %-15s\n" "Filesystem" "Size" "Available"

# Use df command to get disk partition information
df -h 