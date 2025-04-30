#!/bin/bash

# Check if the user provided exactly two arguments (word and file)
if [ $# -ne 2 ]; then
  echo "Usage: $0 <word> <file>"
  exit 1
fi

# Use grep to search for the word in the file, then pipe the results to sort
grep "$1" "$2" | sort

