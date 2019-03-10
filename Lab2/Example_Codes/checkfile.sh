#!bin/bash
if [ -f checkfile.sh ]; then
    echo "File exists"
else
    echo "Ops... checkfile.sh not exist"
fi