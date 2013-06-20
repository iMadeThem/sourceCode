#!/bin/sh

#files='stardict*/'

for f in stardict-*
#for f in $files

do
  echo "Tar ball file: $f"
  tar zcvf $f.tar.bz2 $f
  rm -rf $f
done
