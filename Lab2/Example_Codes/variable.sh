#!/bin/bash

mynum=3150
course_code="csci"
mystr=${course_code}

echo "Before: ${mystr}"
mystr+=${mynum}
echo "After: ${mystr}"

echo "${course_code}3150 is a course about OS"