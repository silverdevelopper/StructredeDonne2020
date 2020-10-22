#ifndef SOURCE_H_
#define SOURCE_H_
#define N 50
void ceasar(char str[N],int t);
void ceasar_decode(char str[N],int t);
void vigenere(char text[N],char key[N]);
void vigenere_decode(char text[N],char key[N]);;
char *matrix_crypting(char str[N]);
char *matrix_decrypting(char str[N]);


#endif