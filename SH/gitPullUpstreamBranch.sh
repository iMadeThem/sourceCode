#!/bin/sh

BIN=/usr/bin
GIT=$BIN/git

# define console output color
RESET="\033[0m"
BOLD="\033[1m"
BLACK="\033[30m"    #  /* Black */
RED="\033[31m"     # /* Red */
GREEN="\033[32m"    #  /* Green */
YELLOW="\033[33m"    #  /* Yellow */
BLUE="\033[34m"     # /* Blue */
MAGENTA="\033[35m"   #   /* Magenta */
CYAN="\033[36m"     # /* Cyan */
WHITE="\033[37m"     # /* White */
BOLDBLACK="\033[1m\033[30m"    #  /* Bold Black */
BOLDRED="\033[1m\033[31m"     # /* Bold Red */
BOLDGREEN="\033[1m\033[32m"    #  /* Bold Green */
BOLDYELLOW="\033[1m\033[33m"    #  /* Bold Yellow */
BOLDBLUE="\033[1m\033[34m"     # /* Bold Blue */
BOLDMAGENTA="\033[1m\033[35m"   #   /* Bold Magenta */
BOLDCYAN="\033[1m\033[36m"     # /* Bold Cyan */
BOLDWHITE="\033[1m\033[37m"     # /* Bold White */

echo ">$CYAN git pull --rebase upstream xxxx ; git push$RESET wrapper tool."

# show which branch we are in
git branch
CURRENT=`git rev-parse --abbrev-ref HEAD`

echo $BR
#echo "In put the branch you would like to sync with upstream: "
echo "You will update current branch $GREEN$CURRENT$RESET by default"
read input

# if input is null, updating the current branch
if [ -z "$input" ]; then
    BRANCH=$CURRENT
else
    BRANCH=$input
fi
#echo "You have chosen branch: $GREEN$input$RESET"

case $BRANCH in
    [mM] | "master"  )
        if [ "$BRANCH" != "$CURRENT" ]; then
            echo "Current branch [$CURRENT] is not the target branch [master], will switch firstly"
            $GIT checkout master
        fi
        echo $GREEN"updating master..."$RESET
        $GIT pull --rebase upstream master
        $GIT push
        ;;
    [dD] | "develop" )
        if [ "$BRANCH" != "$CURRENT" ]; then
            echo "Current branch [$CURRENT] is not the target branch [develop], will switch firstly"
            $GIT checkout develop
        fi
        echo $GREEN"updating develop..."$RESET
        $GIT pull --rebase upstream develop
        ;;
    * )
        echo " $BOLDRED!!!!!!!!!!~~Warning~~!!!!!!!!!!$RESET"
        echo " You have input an unfamous branch:$BOLDRED$BRANCH$RESET"
        echo " Do you really want to update and merge to the branch: $1?(y/n)"
        read option

# MEMO
#       if [  $option  == "y" ] || [  $option  == "Y" ]; then -> this will cause error
        if [ "$option" == "y" ] || [ "$option" == "Y" ]; then
            if [ "$BRANCH" != "$CURRENT" ]; then
                echo "Current branch [$GREEN$CURRENT$RESET] is not the target branch [$RED$BRANCH$RESET], will switch firstly"
                $GIT checkout $BRANCH
                if [ $? -ne 0 ]; then # trying to checkout non-existing branch
                    echo "Branch [$RED$BRANCH$RESET] does not exist, aborting ..."
                    exit
                fi
            fi
#            $GIT pull --rebase upstream $BRANCH
#            $GIT push
            $GIT log
        else
            echo "Nothing happened, exit."
            exit
        fi
        ;;
esac
