gcc -c main.c -o main.o
gcc -c source.c -o source.o
gcc main.c source.o -o main -lm
./main
