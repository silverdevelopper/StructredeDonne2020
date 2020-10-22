#include "source.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void ceasar(char str[N],int t)
{
    int l=strlen(str);
    for (int i = 0; i < l; i++)
    {
        str[i]+=t;
    }
    

}
void ceasar_decode(char str[N],int t){
     int l=strlen(str);
    
    for (int i = 0; i < l; i++)
    {
        str[i]-=t;
    }
}
void vigenere(char text[N],char key[N]){
    int l=strlen(text);
    int k=strlen(key);
     //printf("%d %d\n",l,k);

    for (int i = 0; i < l; i++)
    {
        if(key[k%(i+1)]>64&&key[k%(i+1)]<91)
        text[i]+=(key[k%(i+1)]-'A'+1);
        else
        text[i]+=(key[k%(i+1)]-'a'+1);
    }
}
void vigenere_decode(char text[N],char key[N]){
    int l=strlen(text);
    int k=strlen(key);

    for (int i = 0; i < l; i++)
    {
       if(key[k%(i+1)]>64&&key[k%(i+1)]<91)
        text[i]-=(key[k%(i+1)]-'A'+1);
        else
        text[i]-=(key[k%(i+1)]-'a'+1);
    }
}
char *matrix_crypting(char str[N]){
    // yıldız karakterini kare matrise tamamlamak için kullandım
    int len=strlen(str);
    int d=sqrt(len) +1;
    int lng=pow(d,2);
    char *matrix=malloc(lng);
    char *matrix2=malloc(lng);
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++){
        if((i*d+j)<len)
        matrix[i*d+j]=str[i*d+j];
        else
        matrix[i*d+j]='*';
        printf("%c ",matrix[i*d+j]); 
        }
        printf("\n");
    }
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++){
            matrix2[i*d+j]=matrix[j*d+i];
        }
       
    }
    return matrix2;
}
char *matrix_decrypting(char str[N]){
    int len=strlen(str);
    char *matrix=malloc(len);
    int d=sqrt(len);
    int s=0;
     for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++){
            if(str[i*d+j]=='*')
           { 
               matrix[j*d+i]='\0';

           }
            else
            matrix[j*d+i]=str[i*d+j];
        }
    }
   // printf("%d\n",s);
    return matrix;
}
