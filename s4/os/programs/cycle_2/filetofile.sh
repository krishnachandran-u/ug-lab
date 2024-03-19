#!/bin/bash

exec 3< input.txt

exec 4> output.txt

while IFS= read -r -u 3 line; do
    echo "$line" >&4
done

exec 3<&-
exec 4>&-





