#!/bin/bash

mystr="name.email.phone.remarks"

IFS='.'
for word in ${mystr[@]}; do
    echo $word
done

IFS=" "$'\n'$'\t'