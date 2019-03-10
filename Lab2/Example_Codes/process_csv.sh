#!/bin/bash 
# data.csv must contain an empty line(according to C++ standard)
while read line; do
  echo "${line}" | awk -F',' '{print $1" "$3}'
done < data.csv