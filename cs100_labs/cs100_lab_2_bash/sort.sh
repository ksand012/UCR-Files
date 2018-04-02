#!/bin/bash

Array=(23 34 56 12 5 10)
N=${#Array[@]}
for ((i = 0; i<$N; i++))
do
	for((j=$i; j<$N; j++))
	do
		if [ "${Array[$i]}" -gt "${Array[$j]}" ]; then
			temp=${Array[$i]}
			Array[$i]=${Array[$j]}
			Array[$j]=$temp
		fi
	done
done
for ((i=0; i<$N; i++))
do
	echo ${Array[i]}
done
