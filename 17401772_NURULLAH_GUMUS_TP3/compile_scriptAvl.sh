gcc -c avlUyg.c -o avlUyg.o
gcc -c binaryTree.c -o binaryTree.o
gcc avlUyg.c binaryTree.o -o avlUyg -lm
./avlUyg
