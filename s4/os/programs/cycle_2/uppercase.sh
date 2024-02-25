#!/bin/bash

for filename in $@
do
    tmp_file=$(mktemp)
	sed -e 's/\(.*\)/\U\1/' $filename > $tmp_file 
    mv $tmp_file $filename
done
