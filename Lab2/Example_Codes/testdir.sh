#!/bin/bash

test_dir="/Users/isabella/bash"

if [ ! -d "${test_dir}" ]; then
    mkdir "${test_dir}"
else
    echo "Directory ${test_dir} already exists"
fi
