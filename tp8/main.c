#include "source.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc,char *argv[])
{
     
    char str[50];
    char key[50];
    int t=0;
    printf("Matrix Encrypting\n");
    //3. soru
    printf("Text:\n");
    scanf("%s",str);
    char *matrix;
    matrix=matrix_crypting(str);
    printf("Crypted Text is: %s\n",matrix);
    printf("Decoded Text is: %s\n",matrix_decrypting(matrix));
   
    printf("Vigenere  Encrypting\n");
    //Vigenere  Encrypting
    printf("Text:\n");
    scanf("%s",str);
    printf("Key:\n");
    scanf("%s",key);
    vigenere(str,key);
    printf("Encrypted with vigenere: %s\n",str);
    vigenere_decode(str,key);
    printf("Decoded_vigenere: %s\n",str);

    printf("Yüce Ceasar  Encrypting\n");
    //Yüce Ceasar Encrypting
    printf("Text:\n");
    scanf("%s",str);
    //strcpy(str,argv[1]);
    printf("Transaction:\n");
    scanf("%d",&t);
    //t=atoi(argv[2]);
    ceasar(str,t);
    printf("Şifreli: %s\n",str);
    ceasar_decode(str,t);
    printf("Gerçek hali: %s\n",str);
    
    
 return 0;   
}