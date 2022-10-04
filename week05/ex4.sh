#!/bin/bash

gcc -Wall -pthread ex4.c -o ex4
rm ex4.txt

echo "result of 1 thread" >> ex4.txt
(time ./ex4 10000000 1) 2>> ex4.txt
echo "result of 2 threads" >> ex4.txt
(time ./ex4 10000000 2) 2>> ex4.txt
echo "result of 4 threads" >> ex4.txt
(time ./ex4 10000000 4) 2>> ex4.txt
echo "result of 10 threads" >> ex4.txt
(time ./ex4 10000000 10) 2>> ex4.txt
echo "result of 100 threads" >> ex4.txt
(time ./ex4 10000000 100) 2>> ex4.txt

rm ex4
