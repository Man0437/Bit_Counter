#!/bin/bash
TESTS=100  
PROGRAM=./bit_counter       

for ((i=1;i<=TESTS;i++))
do
SIZE=$((RANDOM % 1024 + 1))

dd if=/dev/urandom of=test.bin bs=1 count=$SIZE status=none

RESULT=$($PROGRAM test.bin)

# Программа для подсчета битов через команду консоли xxd -b
EXPECTED=$(xxd -b test.bin | awk '{for(i=2;i<=NF;i++) if(length($i)==8) printf $i}' | tr -cd '1' | wc -c)

if [ "$RESULT" -ne "$EXPECTED" ]; then
    echo "-----Тест $i Провален-----"
    echo "Вывод программы: $RESULT"
    echo "Ожидается: $EXPECTED"
    exit 1
else
    echo "Тест $i ОК"
fi

done

echo "Все тесты пройдены"