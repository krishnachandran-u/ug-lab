#!/bin/bash

exec 3< input.txt

while IFS= read -r -u 3 line; do 
    echo "$line"
done

exec 3<&-
