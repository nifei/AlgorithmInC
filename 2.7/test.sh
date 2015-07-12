#!/bin/sh
echo "compiling..."
g++ Permutation.cpp
time ./a.out 10000 1
sleep 1
time ./a.out 10000 2
sleep 1
time ./a.out 10000 3
