#include "kdTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


kdNode* create_tree(char name[size],char key,int data[]){
    kdNode *tmp=malloc(sizeof(kdNode));
    strcpy(tmp->name,name);
    tmp->key=key;
    int i;
    for (int i = 0; i < K; i++)
    {
        tmp->data[i]=data[i];
    }
    
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}
void insertR(kdNode** head, char name[size],char key,int data[K], unsigned depth){
    if(*head == NULL){
        
    *head = create_tree(name, key, data);
    return;
    }

    unsigned cd= depth%K;
  
        if(data[cd]<(*head)->data[cd])
        insertR(&(*head)->left,name,key,data,depth+1);
        else
        insertR(&(*head)->right,name,key,data,depth+1);
    

}
void insert(kdNode** root, char name[size],char key,int x,int y){
    int data[K]={x,y};

    insertR(root,name,key,data,0);
}
void printNode(kdNode *node)
{
    if(node==NULL)
    return;
    printf("Nod:\nname: %s - key: %c - x: %d - y:%d\n",node->name,node->key,node->data[0],node->data[1]);
}
int getLevel(kdNode *node){
    if(node == NULL)
    {
        return 0;
    }
    int x=1+getLevel(node->left);
    int y=1+getLevel(node->right);
    return max(x,y);
}
int max(int x,int y){
    if(x>y)
    return x;
return y;
}
kdNode* search_port(kdNode* root,char name[size]){
    kdNode* tmp=NULL;
    if(root==NULL)
    return tmp;
    if(strcmp(root->name,name)==0)
    {
        tmp= root;
        return tmp;
    }
    tmp=search_port(root->left,name);
    if(tmp==NULL)
    tmp=search_port(root->right,name);

return tmp;
}
kdNode* search_index(kdNode* root,char key){
    kdNode* tmp=NULL;
    if(root==NULL)
    return tmp;
    if(root->key==key)
    {
        tmp= root;
        return tmp;
    }
    tmp=search_index(root->left,key);
    if(tmp==NULL)
    tmp=search_index(root->right,key);

return tmp;
}
void print_inorder(kdNode* root){
    if(root == NULL)
    return;
    print_inorder(root->left);
    printNode(root);
    print_inorder(root->right);
}
void print_postorder(kdNode* root){
    if(root == NULL)
    return;
    print_postorder(root->left);
    print_postorder(root->right);
    printNode(root);
}
void print_preorder(kdNode* root){
    if(root == NULL)
    return;
    printNode(root);
    print_preorder(root->left);
    print_preorder(root->right);
}
void freeTree(kdNode** root)
{
    if(*root==NULL)
        return;
    kdNode **templ,**tempr;
    templ=&(*root)->left;
    tempr=&(*root)->right;
    free(*root);
    *root=NULL;
    freeTree(templ);
    freeTree(tempr);
    
}