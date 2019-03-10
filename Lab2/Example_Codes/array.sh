#!/bin/bash

myarray=("three" 1 "five" 0)
myarray[2]="eight"
myarray[5]="!"
echo "The first item in ${myarray[0]}"
echo "All items are ${myarray[@]}"
echo "The number of the array is ${#myarray[@]}"
echo "The key of the array is ${!myarray[@]}"

