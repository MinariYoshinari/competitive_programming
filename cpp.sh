#!/bin/sh
clang++ -o out $1 -std=c++11
./out < ./testcase.txt #いずれは複数のテストケースを一気に試せるようになりたい
rm out