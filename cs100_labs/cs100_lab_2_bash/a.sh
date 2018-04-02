#!/bin/sh
read -p 'Hello. What would you like to say?: ' varname

echo "Here's the first word of what you said: " 
echo
echo $varname | awk '{print $1;}'
