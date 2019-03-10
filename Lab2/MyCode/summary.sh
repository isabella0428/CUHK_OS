#!/bin/bash
content=$(ls | grep "^.*\.sh")
echo ${content}
for item in ${content}; do
    echo ${item}
    chars=$(wc -c ${item})
    chars=($chars)
    chars=${chars[0]}

    words=$(wc -w ${item})
    words=($words)
    words=${words[0]}

    lines=$(wc -l ${item})
    lines=($lines)
    lines=${lines[0]}

    echo "${chars} chars, ${words} words, ${lines} lines"
done > $1