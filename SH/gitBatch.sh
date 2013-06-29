#!/bin/sh

### will not show color
##!/usr/bin/env bash
#set -e
#set -u
#set -o pipefail

# terminal color setting
RESET="\033[0m"
BOLD="\033[1m"
UNDERLINE="\033[4m"
BLACK="\033[30m"      # Black
RED="\033[31m"        # Red
GREEN="\033[32m"      # Green
YELLOW="\033[33m"     # Yellow
BLUE="\033[34m"       # Blue
MAGENTA="\033[35m"    # Magenta
CYAN="\033[36m"       # Cyan
WHITE="\033[37m"      # White
BOLDBLACK="\033[1m\033[30m"    # Bold Black
BOLDRED="\033[1m\033[31m"      # Bold Red
BOLDGREEN="\033[1m\033[32m"    # Bold Green
BOLDYELLOW="\033[1m\033[33m"   # Bold Yellow
BOLDBLUE="\033[1m\033[34m"     # Bold Blue
BOLDMAGENTA="\033[1m\033[35m"  # Bold Magenta
BOLDCYAN="\033[1m\033[36m"     # Bold Cyan
BOLDWHITE="\033[1m\033[37m"    # Bold White


#THIS_DIR="$( dirname "${BASH_SOURCE[0]}" )"

if [ -z "${REPO_ROOT+set}" ]; then
    echo "Before proceeding, you should set REPO_ROOT environment variable!"
    exit
fi

echo "Inspecting the repository root: $REPO_ROOT"
cd $REPO_ROOT

start_time=`date +%s`

DIRS=`ls -d -- */`
CMD=$0
if [ $# == 0 ]; then
    echo "USAGE:"
    echo "  $GREEN${CMD##*/} [pull/status]$RESET"
    echo "$DIRS"
else
    counter=0
    # execute command from folders
    for DIR in $DIRS
    do
        pushd $REPO_ROOT/$DIR
        PWD=`pwd`
        echo $PWD
        REPOS=`find . -name \.git -type d`
        for REPO in $REPOS
        do
            pushd $PWD/$REPO/../ || exit 1
            ((counter++))
            echo "$counter ===> $CYAN `git rev-parse --show-toplevel` $RESET"
            git $1 || exit 1
            popd
        done
        popd
    done
    if [ $? == 0 ]; then
        echo "Updated$BOLDRED $counter$RESET repositories by$GREEN git $1$RESET"
    fi
fi

end_time=`date +%s`
echo Execution time:$BOLDGREEN `expr $end_time - $start_time` Seconds$RESET.
