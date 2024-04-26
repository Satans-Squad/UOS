#!/bin/bash

# Check if URL is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <URL>"
    exit 1
fi

url="$1"

# Download webpage using wget
wget -O downloaded_page.html "$url"

# Check if wget command was successful
if [ $? -eq 0 ]; then
    echo "Webpage downloaded successfully."
else
    echo "Failed to download webpage."
fi
