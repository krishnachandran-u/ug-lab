#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Input command line argument, sweetie."
    exit 1
fi

file_content=$(cat "$1")

tr '[:lower:]' '[:upper:]' < "$1" > "$1.upper"

echo "Done"



