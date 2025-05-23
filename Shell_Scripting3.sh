#!/bin/bash

echo "How many numbers do you want to add?"
read n

arr=()
sum=0

echo "Enter $n numbers:"

for (( i=0; i<n; i++ ))
do
  read num
  arr+=("$num")
done

for num in "${arr[@]}"
do
  sum=$((sum + num))
done

echo "The sum of the entered numbers is: $sum"
