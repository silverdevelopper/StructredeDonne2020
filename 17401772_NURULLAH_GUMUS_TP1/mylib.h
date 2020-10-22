
#ifndef MYLIB_H_
#define MYLIB_H_

int isLetter(char c);
int isDigit(char c);
int isEven(int value);
int isPrime(int value);
int digitSum(int value);
int reverseNumber(int value);
void upperCase(char c);
void downcase(char c);
int isUpperCase(char c);
int factoriel(int value);
int power(int base, int degree);
int add(int value1, int value2);
void findRoots(int a, int b, int c);

int exist(int *arr, int size, int value);
int getIndex(int *arr, int size, int value);
int count(int *arr, int size, int value);
int findMax(int *arr, int size);
int findMax2(int *arr, int size);
int findMin(int *arr, int size);
int findMin2(int *arr, int size);
double averageArr(int *arr, int size);
double deviationArr(int *arr, int size);
int sumArray(int *arr, int size);
void printArray(int *arr,int size);
int isPalindromeNumber(int value);
int isVowel(char c);
int isPalindromeText(char *c, int size);
int** fillMatrix(int **matrix, int row, int column);
void printMatrix(int **matrix, int row, int column);
int** transposeMatrix(int **matrix,int **matrix2, int row, int column);

// Hail Stone numbers ile ilgili pdfde komut yoktu hocam

/**
void hailstoneNumbers(int value);

 * 
*/


#endif 