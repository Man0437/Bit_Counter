#!/bin/bash

PROGRAM=./countbits
TESTS=100         

for ((i=1;i<=TESTS;i++))
do
SIZE=$((RANDOM % 1024 + 1))

dd if=/dev/urandom of=test.bin bs=1 count=$SIZE status=none

RESULT=$($PROGRAM test.bin | grep -o '[0-9]\+')
EXPECTED=$(xxd -b test.bin | tr -cd '1' | wc -c)

if [ "$RESULT" -ne "$EXPECTED" ]; then
    echo "Test $i FAILED"
    echo "Program result: $RESULT"
    echo "Expected: $EXPECTED"
    exit 1
else
    echo "Test $i OK"
fi

done

echo "All tests passed!"
