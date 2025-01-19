#!/bin/bash

# Seed the random number generator with the current epoch time
RANDOM=$(date +%s)

# Check if a 4-digit integer is provided as an argument:
if [[ $# -eq 0 ]]; then
    # If not, generate a random 4-digit integer
    input=$((RANDOM % 9000 + 1000))
    echo "No input provided. Randomly generated 4-digit integer: $input"
elif [[ $1 =~ ^[0-9]{4}$ ]]; then
    # If so, use the provided 4-digit integer
    input=$1
else
    echo "Usage: $0 <4-digit-integer> (or without arguments for random input generation!)"
    exit 1
fi

# Generate the hash using SHA-256
hash=$(echo -n "$input" | sha256sum | awk '{print $1}')

echo "Input: $input"
echo "Hash:  $hash"

# Check if the input is already in hash_output.txt:
if grep -q "SHA256 hash of $input: $hash" hash_output.txt 2>/dev/null; then
    # If so, do not add it again
    echo "Hash of $input already exists in hash_output.txt. No changes made."
else
    # If not, save the hash to hash_output.txt
    echo "SHA256 hash of $input: $hash" >> hash_output.txt
    echo "The hash saved in hash_output.txt"
fi
