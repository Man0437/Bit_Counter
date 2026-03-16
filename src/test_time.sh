#!/bin/bash

DIR="../files"
PROGRAM=./bit_counter

for file in "$DIR"/*; do
    echo "Файл: $file"
    start=$(date +%s%3N)

    # ./bit_counter <file>
    $PROGRAM "$file"
    end=$(date +%s%3N)
    echo "Время выполнения: $((end - start)) ms"
    du -h "$file"
    echo "-------------------------------------"
done