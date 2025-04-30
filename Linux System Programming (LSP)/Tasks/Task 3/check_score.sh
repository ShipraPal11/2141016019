#!/bin/bash

# Declare a string variable
name="Shipra"

# Declare an integer variable
score=85

# Use an if-else statement to evaluate the integer
if [ "$score" -ge 80 ]; then
    echo "$name has a high score: $score"
else
    echo "$name needs to keep trying. Score: $score"
fi
