#!/bin/bash

echo "Enter the filename (with extension if any):"
read filename

touch "$filename"

if [ -e "$filename" ]; then
  echo "File '$filename' exists."
else
  echo "File '$filename' does NOT exist."
fi

