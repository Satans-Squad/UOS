#!/bin/bash

tput bold
tput blink

echo "$(tput setaf 1}Hello World$(tput sgr0)"
echo "$(tput setaf 0)Hello World$(tput sgr0)"

tput sgr0  # Reset attributes to default
