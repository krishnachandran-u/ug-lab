#!/bin/bash

exec 4> output.txt

while IFS= read -r line; do
  echo "$line" >&4
done

exec 4>&/dev/null

