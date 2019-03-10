#!/bin/bash
function addition {
    echo "$1"
    result=0
    for i in $@;  do
        result=$((${result} + ${i}))
    done
}

function main {
    local a=1
    local b=2
    result=
    addition ${a} ${b}
    echo "${a}+${b}=${result}"
}

main