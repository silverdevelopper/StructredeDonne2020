#ifndef KDTREE_H_
#define KDTREE_H_
#define size 200
#define K 2
typedef struct nodee {
    char name[size];
    char key;
    struct  nodee *left,*right;
    int data[K];
}kdNode;
kdNode* create_tree(char name[size],char key,int data[K]);
void insertR(kdNode** head, char name[size],char key,int data[K], unsigned depth);
void insert(kdNode** root, char name[size],char key,int x,int y);
void printNode(kdNode* node);
int getLevel(kdNode *node);
int max(int x,int y);
kdNode* search_port(kdNode* root,char name[size]);
kdNode* search_index(kdNode* root,char key);
void print_inorder(kdNode* root);
void print_preorder(kdNode* root);
void print_postorder(kdNode* root);
void freeTree(kdNode** root);
#endif