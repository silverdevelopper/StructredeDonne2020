#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include "binaryTree.h"
int main()
{
   binaryTree *root=NULL; 
    root = insertAvl(root, 10,"Almanya"); 
    inorder(root);
    printf("\n\n"); 
    root = insertAvl(root, 20,"Arjantin"); 
    inorder(root);
    printf("\n\n"); 
    root = insertAvl(root,30,"Avustralya"); 
    inorder(root);
    printf("\n\n"); 
    root = insertAvl(root, 40,"Avusturya"); 
    inorder(root);
    printf("\n\n"); 
    root = insertAvl(root, 50,"Meksika"); 
    inorder(root);
    printf("\n\n"); 
    root = insertAvl(root, 25,"Belçika"); 
    inorder(root);
    printf("\n\n"); 
    root=deleteAvl(root,40);
    inorder(root);
    printf("\n\n"); 
    root=deleteAvl(root,20); 
    inorder(root);
    printf("\n\n"); 
    root=deleteAvl(root,25);
    inorder(root);
    printf("\n\n"); 
    preorder(root);
 
   
   
return 0;
}
