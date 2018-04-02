#!/bin/sh

if [ $# -eq 3 ]
then
	if [ $1 -gt $2 ] && [ $1 -gt $3 ]
	then
	echo $1

	elif [ $2 -gt $1 ] && [ $2 -gt $3 ]
	then
	echo $2

	elif [ $3 -gt $1 ] && [$3 -gt $1 ]
	then
	echo $3
	fi
else
echo "Error.  Not all parameters passed through."
fi
