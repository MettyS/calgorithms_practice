#!/usr/bin/env bash

cflags="-g -O0 -Wall -Wextra -Werror"

echo "Compile leetcode5.c"
gcc -c $cflags -o leetcode5.o leetcode5.c
echo "Link leetcode5"
gcc -o leetcode5 leetcode5.o

echo "Compile linkedlist.c"
gcc -c $cflags -o linkedlist.o linkedlist.c
echo "Compile linkedlist tests"
gcc -c $cflags -o linkedlisttest.o linkedlisttest.c
echo "Link linkedlisttests"
gcc -o linkedlisttests linkedlist.o linkedlisttest.o

echo "Compile binarytree.c"
gcc -c $cflags -o binarytree.o binarytree.c
echo "Compile binarytree tests"
gcc -c $cflags -o binarytreetest.o binarytreetest.c
echo "Link binarytree"
gcc -o binarytreetests binarytree.o binarytreetest.o