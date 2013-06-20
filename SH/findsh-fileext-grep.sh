#!/bin/sh
#echo " - Number of params: $#"

if [ $# == 1 ]; then
#    echo " - Grep: $1"
    find . -name \*.* | xargs grep -Hn --color $1
elif [ $# == 2 ]; then
#    echo " - Grep files: *.$1, of: "$2" "
    find . -name \*.$1 | xargs grep -Hn --color $2
else
    echo "Usage:"
    echo "  findsh-fileext-grep.sh [file_extention] grep_content"
    exit 0
fi


