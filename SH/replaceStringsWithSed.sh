#!/bin/sh

# Find FILE_NAME files under current folder recursively
# then replace some string with new string expression

for file in $( find . -name \FILE_NAME )
do
    echo $file
#    cat $file
    sed -e "s|string-to-be-replaced|string-to-replace|g" $file > $file.temp || exit $?
    mv $file.temp $file || exit $?
done
