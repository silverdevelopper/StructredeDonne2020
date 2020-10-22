gcc -c kdTreeTest.c -o kdTest.o
gcc -c kdTree.c -o kdTree.o
gcc kdTreeTest.c kdTree.o -o kdTest -lm
./kdTest
