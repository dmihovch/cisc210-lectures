#!/usr/bin/env bash

echo "r = 100 = 4, w = 010 = 2, x = 001 = 1"
echo "rwx = 111 = 7, rw- = 110 = 6, r-x = 101 = 5, r-- = 100 = 4"

touch chmod-demo.txt
ls -l chmod-demo.txt

chmod 755 chmod-demo.txt
ls -l chmod-demo.txt

chmod 600 chmod-demo.txt
ls -l chmod-demo.txt

rm chmod-demo.txt

exit 0