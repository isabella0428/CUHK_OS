#!/bin/bash
mystr="This is an OS course!"
for item in ${mystr}; do
    echo ${item}
done
if [ -z "${mystr}" ]; then
    echo "This string is empty"
else
    #echo "This string is not empty"
    echo ${mystr}
fi