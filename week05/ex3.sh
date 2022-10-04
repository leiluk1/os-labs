#!/bin/bash

gcc -Wall -pthread ex3.c -o ex3
rm ex3.txt

echo "result of 1 thread" >> ex3.txt
(time ./ex3 10000000 1) 2>> ex3.txt
echo "result of 2 threads" >> ex3.txt
(time ./ex3 10000000 2) 2>> ex3.txt
echo "result of 4 threads" >> ex3.txt
(time ./ex3 10000000 4) 2>> ex3.txt
echo "result of 10 threads" >> ex3.txt
(time ./ex3 10000000 10) 2>> ex3.txt
echo "result of 100 threads" >> ex3.txt
(time ./ex3 10000000 100) 2>> ex3.txt

rm ex3
