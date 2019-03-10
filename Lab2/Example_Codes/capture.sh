#!/bin/bash

#capture stdout
output=$(ls)
echo ""
echo "Output of ls: ${output}"

#what is the exit status?
echo ""
haha;echo "haha gives $?";

echo ""
echo "hello, world!"
echo "echo gives $?"