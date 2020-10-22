#include "mylib.h"
#include "math.h"
#include <stdio.h>
#include <time.h> 
#include <stdlib.h> 
int isLetter(char c){
    // a remplir
    if ((c>='a' && c<='z') || (c>='A'&&c<='Z'))
    {
        /* code */
        return 1;
    }else
    {
        return 0;
    }
    
    
}
int isDigit(char c)
{
    if (c>=48&&c<=57)
    {
        /* code */
        return 1;
    }else
    {
        return 0;
    }
}
int isEven(int value){
return value%2? 0:1;
}
int isPrime(int value){
    int i=2;
    if(value==2)
    return 1;
    while (value%i!=0)
    {
        /* code */
        if(i>sqrt(value)){
            return 1;
        }
        i++;
    }
    return 0;
}
int digitSum(int value){
    int top=0;
    top=value%10;
    while (value/10!=0)
    {
        value=value/10;
        top+=value%10;
    }
    return top;
}
int reverseNumber(int value){
    int digit=1;
    int temp=value;
    int top=0;
    while (value/10!=0)
    {
        value=value/10;
        digit++;
    }
    int bas=0;
    while (digit)
    {
        //printf("% d ",digit);
        bas=temp%10;
        top += bas*pow(10,digit-1);
        digit--;
        temp=temp/10;

    }
    return top;
}
//
//

void downcase(char c){
    
    if(c>='A'&&c<='Z')
    {
        c+='a'-'A';
        printf("%c --> %c \n",c-32,c);
    }else
    {
        printf("\n %c Char değil\n",c);
    }

}
void upperCase(char c)
{
      if(c>='a'&&c<='z')
    {
        c-='a'-'A';
        printf("%c --> %c \n",c+32,c);
    }else
    {
        printf("\n %c Char değil\n",c);
    }
}
int isUpperCase(char c){
    if(c>='A'&&c<='Z')
    return 1;
    else
    return 0;
}
int factoriel(int value){
    if(value==0||value==1)
    return 1;
    else if(value>1)
    return value*factoriel(value-1);
    else return -1;
}
int power(int base, int degree){
    int i=degree;
    int mult=base;
    for ( i = degree-1; i!=0; i--)
    {
        base*=mult;
    }
    return base;
    
}
int add(int value1, int value2){
    return value1+value2;
}
void findRoots(int a, int b, int c){
    double determinant=sqrt(b*b-4*a*c);
    printf("x'%d + %dx + %d --> roots are %.2f, %.2f\n",a,b,c,(-b+determinant)/(2*a),(-b-determinant)/(2*a));
}
int exist(int *arr, int size, int value)
{
    int i;
    for ( i = 0; i < size; i++)
    {
        if (arr[i]==value)
        {
            printf("Aradığınız değer dizide var\n");
            return 1;
        }
        
    }
     printf("Aradığınız değer dizide yok!\n");
    return 0;
}
int getIndex(int *arr, int size, int value){
    int i;
    for ( i = 0; i < size; i++)
    {
        if (arr[i]==value)
        {
            return i;
        }
        
    }
    return -1;
}
int count(int *arr, int size, int value){
    int i,count=0;
    for ( i = 0; i < size; i++)
    {
        if (arr[i]==value)
        {
            count++;
        }
        
    }
    return -count;
}
int findMax(int *arr, int size){
int i; int res=arr[0];
    for ( i = 0; i < size; i++)
    {
        if (arr[i]>res)
        {
            res=arr[i];
        }
        
    }
    return res;
}
int findMax2(int *arr, int size){
    int i,j,temp; int max2=arr[0];
    for ( i = 0; i < 2; i++)
    {
        for ( j = i; j < size; j++)
        {
            if (arr[j]>max2)
            {
                max2=arr[j];
               temp=arr[i];
               arr[i]= arr[j];
               arr[j]=temp;
            }            
        }
        
    }
    return max2;
}
int findMin(int *arr, int size){
    int i; int res=arr[0];
    for ( i = 0; i < size; i++)
    {
        if (arr[i]<res)
        {
            res=arr[i];
        }
        
    }
    return res;
}
int findMin2(int *arr, int size){
    int i,j,temp; int min2=arr[0];
    for ( i = 0; i < 2; i++)
    {
        for ( j = i; j < size; j++)
        {
            if (arr[j]<min2)
            {
               min2=arr[j];
               temp=arr[i];
               arr[i]= arr[j];
               arr[j]=temp;
            }            
        }
        
    }
    return min2;
}
double averageArr(int *arr, int size){
    int i; double average=0;
    for ( i = 0; i < size; i++)
    {
        average+=arr[i];
        /* code */
    }
    return (average/(double)size);
}
double deviationArr(int *arr, int size){
    double average=averageArr(arr,size);
    double top=0,res=0;
    int i;
    for ( i = 0; i < size; i++)
    {
        top+=pow(arr[i]-average,2);
    }
    top=(double)top/(size-1);
    res=sqrt(top);
    return res;
}
int sumArray(int *arr, int size){
    int i; int top=0;
    for ( i = 0; i < size; i++)
    {
        top+=arr[i];
    }
    
    return top;
}
void printArray(int *arr,int size){
    int i;
    printf("Printing Array...\n");
    for(i=0;i<size;i++){
    printf("%d ",arr[i]);
    }
    printf("\n");
}
int isPalindromeNumber(int value){
    if(value==reverseNumber(value))
    {
        printf("It is polindrom %d\n",value);
        return 1;
    }
    printf("It is not polindrom %d\n",value);
    return 0;
}
int isPalindromeText(char *c, int size)
{
    int i=0;
    for ( i = 0; i < size; i++)
    {
        if(c[i]!=c[size-i-1])
        {
            printf("%s: is not polindrom\n",c);
            return 0;
        }
    }
    printf("%s: is  polindrom\n",c);
    return 1;
}
//a e i o u
int isVowel(char c){
char vowels[5]={'a','e','i','o','u'};
int i;
for(i=0;i<5;i++)
if(c==vowels[i]){
    printf("%c It is vowel\n",c);
    return 1;
}

printf("%c is not vowel\n",c);
return 0;
}
int** fillMatrix(int **matrix, int row, int column){
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            matrix[i][j]=rand()%(100-50)+50;
        }
    }
    
    return matrix;
}
void printMatrix(int **matrix, int row, int column){
    int i,j;
    printf("Matris...\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
           printf("%d   ",matrix[i][j]);
        }
        printf("\n");
    }
}
int** transposeMatrix(int **matrix,int **matrix2, int row, int column){
    int i, j,temp; 
    printf("Transposing\n");
    for (i = 0; i < row; i++) 
        for (j = 0; j < column; j++)
        {  
         matrix2[i][j]=matrix[j][i];  
        }

    return matrix2;
}
// ...