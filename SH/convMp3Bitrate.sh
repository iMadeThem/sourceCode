#!/usr/bin/env bash
set -e
set -u
set -o pipefail

PWD=`pwd`
echo "\"$PWD\": continue? (y/n)"

read cmd
if [ "$cmd" == "y" ]; then
    OLDIFS="$IFS"  # save default IFS(Internal Field Separator)
    IFS=""         # don't split on any white space

    find $PWD -iname "*.mp3" | while read F;
    do
        F=`echo "$F" | sed -e "s/\ /\\ /g"`
#        echo "$F"
        pathname=${F%/*}      # pathname="$(dirname $F)"
        filename=${F##*/}     # filename="$(basename $F)"
        prefix=${filename%.*}
        suffix=${filename##*.}
        dis="$pathname"/"$prefix"_128k."$suffix"
        `ffmpeg -b:a 128k -i "${F}" "$dis"`
        echo "Converted to: $dis"
    done

    IFS=$OLDIFS     # restore IFS
fi