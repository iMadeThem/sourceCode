#!/bin/sh
echo "================================================================================"
git config -l

git config --global core.editor emacs
git config --global core.pager less

git config --global alias.cl 'config -l'
git config --global alias.st status
git config --global alias.ci commit
git config --global alias.co checkout
git config --global alias.br branch

git config --global user.name "Leon He"
git config --global user.email yong.he1982@gmail.com

git config --global color.branch auto
git config --global color.diff auto
git config --global color.interactive auto
git config --global color.status auto

# Opendiff (FileMerge) to resolve merge conflicts:
git config --global merge.tool opendiff

# Change the font in gitk: Open ~/.gitk and add:
#set mainfont {Monaco 12}
#set textfont {Monaco 12}
#set uifont {Monaco 12}

# Global ignore file:
#echo ".DS_Store" >> ~/.gitignore
#git config --global core.excludesfile ~/.gitignore

echo "================================================================================"
git cl
