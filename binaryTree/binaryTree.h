#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#define size 15

typedef struct nodee {
    char name[size];
    char key;
    struct  nodee *left,*right;
    int x,y;
}kdNode;
kdNode* create_tree(char name[size],char key,int x,int y);
void insertR(kdNode** head, char name[size],char key,int x,int y, unsigned depth);
void insert(kdNode** root, char name[size],char key,int x,int y);
void printNode(kdNode* node);
#endif