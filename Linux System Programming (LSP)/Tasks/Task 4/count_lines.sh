#!/bin/bash

# Function to count and print the number of lines in a file
count_lines_in_file() {
    local file=$1

    if [ -f "$file" ]; then
        line_count=$(wc -l < "$file")
        echo "$file has $line_count lines."
    else
        echo "$file not found."
    fi
}

# List of file names (you can modify this list)
files=("file1.txt" "file2.txt" "file3.txt")

# Loop through the file list and call the function
for file in "${files[@]}"; do
    count_lines_in_file "$file"
done
