#!/bin/bash

for filename in $@
do
	sed -e 's/\(.*\)/\U\1/' $filename 
done
