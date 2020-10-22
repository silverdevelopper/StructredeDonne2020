gcc -c mylib.c -o mylib.o
gcc -c test.c -o test.o
gcc test.c mylib.o  -o test -lm
./test

