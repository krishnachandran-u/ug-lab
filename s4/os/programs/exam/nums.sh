#!/bin/bash

for i in {1..3}; do
    for j in {0..3}; do
        for k in {0..3}; do
            echo "$i$j$k"
        done
    done 
done
