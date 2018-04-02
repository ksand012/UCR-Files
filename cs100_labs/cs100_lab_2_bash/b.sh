#!/bin/sh

read -p 'Please enter your first name: ' firstname
echo
read -p 'Please enter your last name: ' lastname
echo
concatname=$firstname$lastname
echo "Your concatenated name: " $concatname
