#!/bin/sh

mylongstr="This is a long string"
echo "My string is ${mylongstr}"
echo ""

echo "Number of characters the string: ${#mylongstr}"
echo ""

echo "Splitting my string like an array:"
for word in ${mylongstr[@]}; do
    echo "${word}"
done
echo ""



