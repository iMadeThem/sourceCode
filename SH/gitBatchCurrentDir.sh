#!/bin/sh

source libcolor.sh

#SCRIPT_DIR="$( dirname "${BASH_SOURCE[0]}" )"

CURR_DIR=`pwd`

DIRS=`ls -d -- */`

if [ ! -d "$CURR_DIR" -o -z "$DIRS" ]; then
    echo "It seems you are not in a correct directory or no sub-directories found, ABORTING..."
    exit
fi


echo "Inspecting the repository root: $CURR_DIR"
#cd $CURR_DIR

start_time=`date +%s`

CMD=$0
if [ $# == 0 ]; then
    echo "USAGE:"
    echo "  $GREEN${CMD##*/} [pull/status/ALIASes]$RESET"
    echo "$DIRS"
else
    counter=0
    # execute command from folders
    for DIR in $DIRS
    do
        pushd $CURR_DIR/$DIR
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
