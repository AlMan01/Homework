#!/bin/bash

echo -n
read n
for ((i = 0; i < n; ++i))
do
	echo "Hello, World<i-th>" > Homework_2_$i
done
