#!/bin/bash
content=$(ls | grep "^.*\.sh") 
for i in "${content}"; do
    echo -n "$i"
done


