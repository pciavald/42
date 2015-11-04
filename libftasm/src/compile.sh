#!/bin/sh

nasm -f macho64 -o obj.o $1
gcc -c -o main.o main.c
gcc -c -o `echo $1 | sed 's/\.s/\.o/'` `echo $1 | sed 's/\.s/\.c/'`
ld -macosx_version_min 10.8 -lSystem *.o
./a.out
rm *.o
