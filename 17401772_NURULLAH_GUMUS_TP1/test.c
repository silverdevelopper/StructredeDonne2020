#include <stdio.h>
#include <math.h>
#include "mylib.h"
#include <time.h> 
#include <stdlib.h> 

// to complile from terminal, run: gcc test.c mylib.c -o ApplicationName -lm
// to run the complied application, run: ./ApplicatioName

int main(void)
{
    int val=0;    // a remplir
    srand(time(0));
    val=rand()%1000+1;
    // Test 1
    //....
    if(isPrime(val))
    printf("\n%d is Prime \n",val);
    else
    printf("%d is not Prime \n",val);
    // test 2
    // ...
    if(isEven(val))
    printf("%d is Even \n",val);
    else
    {
        printf("%d is not Even \n",val);
    }
    
    printf("%d --> %d\n",val,digitSum(val));
    printf("%d --> %d\n",val,reverseNumber(val));
    //
        val=rand()%('z'+1-'a')+'a';
    upperCase(val);
    val=rand()%('Z'+1-'A')+'A';
    downcase(val);
    val=rand()%('Z'+1-'A')+'A';
     if(isUpperCase(val))
     printf("%c --> It's upper case\n",val);
     else
     printf("It is not upper case\n");

    val=rand()%10;
    if(factoriel(val)!=-1)
     printf("%d! = %d \n",val,factoriel(val));
     else
     printf("Error: \n");
     int val1=rand()%1000,val2=rand()%500;
     printf("Addition: %d + %d = %d\n",val1,val2,add(val1,val2));
     int base=rand()%6+1;
     int degree=rand()%3+1;
     printf("%d^%d =%d\n",base,degree,power(base,degree));
     findRoots(1,4,4);
     findRoots(1,5,6);
     int size=10;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i]=rand()%(1000-50+1)+50;
    }
    printArray(arr,size);
    int finding_num=rand()%(100-50+1)+50;
    exist(arr,size,finding_num);
    int ind=getIndex(arr,size,finding_num);
    if(ind==-1)
    printf("%d n'existe pas\n",finding_num);
    else
    {
        printf("Index:%d\n",ind);
    }
    printf("Count of %d in the array is:%d\n",finding_num,count(arr,size,finding_num));
    printf("Min of array:%d Min2 of array:%d\n",findMin(arr,size),findMin2(arr,size));
    printf("Max of array:%d Max2 of array:%d\n",findMax(arr,size),findMax2(arr,size));
    printf("Avarage: %.2f - Devitation: %.2f - SumArray: %d\n",averageArr(arr,size),deviationArr(arr,size),sumArray(arr,size));
    isPalindromeNumber(2552);
    isPalindromeNumber(100);
    isPalindromeNumber(333);
    isPalindromeText("sas",3);
    isPalindromeText("ana",3);
    isPalindromeText("babababab",9);
    isPalindromeText("hercai",6);
    isVowel('a');
    isVowel('z');
    int size2=5;
     int *matrix[size2];int *matrix2[size2]; 
     int i;
    for (i=0; i<size2; i++){
         matrix[i] = (int *)malloc(size2 * sizeof(int));
         matrix2[i] = (int *)malloc(size2 * sizeof(int)); 
    }
    fillMatrix(matrix,size2,size2);
    printMatrix(matrix,size2,size2);
    printf("------------------\n");
    transposeMatrix(matrix,matrix2,size2,size2);
    printMatrix(matrix2,size2,size2);
    return 0;
}
