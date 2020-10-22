#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 15
#define k 2

kdNode* create_tree(char name[size],char key,int x,int y){
    kdNode* tmp=malloc(sizeof(kdNode));
    strcpy(tmp->name,name);
    tmp->key=key;
    tmp->x=x;
    tmp->y=y;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}
void insertR(kdNode** head, char name[size],char key,int x,int y, unsigned depth){
    if(*head==NULL){
    *head=create_tree(name, key, x, y);
    return;
    }
    unsigned cd= depth%k;
    if(cd==0){
    insertR(&(*head)->left,name,key,x,y,depth);
    }else{
    insertR(&(*head)->right,name,key,x,y,depth+1);
    }
    return;

}
void insert(kdNode** root, char name[size],char key,int x,int y){
    insertR(root,name,key,x,y,0);
}
void printNode(kdNode *node)
{
    printf("Nod:\nname: %s - key: %c - x: %d - y:%d\n",node->name,node->key,node->x,node->y);
}