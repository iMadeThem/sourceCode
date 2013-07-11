#!/bin/sh

source libcolor.sh

BIN=/usr/bin
GIT=$BIN/git

REMOTE=`$GIT remote | tr "\n" " "`

echo ">$BLUE Create a branch in \"$REMOTE\".$RESET"
git branch -a

echo "Input the branch: (only xxxx of feature/xxxx)"
read  BRANCH
BRANCH="feature/"$BRANCH
echo "Do you want to create branch: $BOLDRED$BRANCH$RESET (y/n)"

read option
if [ "$option" == "y" ] || [ "$option" == "Y" ]; then
    echo "Creating branch..."
    $GIT checkout -b $BRANCH
    for r in $REMOTE; do
        echo "Push branch to repository:$RED $r $RESET?(y/n)"
        read conf
        if [ "$conf" == "y" ] || [ "$conf" == "Y" ]; then
            $GIT push -u $r $BRANCH
            echo "......Working on repository: "$r
            if [ $? -ne 0 ]; then # trying to checkout non-existing branch
                echo "Branch [$RED$BRANCH$RESET] creation failed, aborting ..."
                exit
            fi
            echo "Branch has been created in$RED \"$r\"$RESET!\n\n"
        fi
    done
    echo "---------- Current Status ----------"
    $GIT config -l | grep remote | sort
fi

exit
