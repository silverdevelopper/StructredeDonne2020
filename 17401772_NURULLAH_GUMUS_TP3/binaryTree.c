#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

binaryTree *newNode(int item, char name[size])
{
    binaryTree *tmp = malloc(sizeof(binaryTree));
    tmp->key = item;
    tmp->left = NULL;
    tmp->right = NULL;
    strcpy(tmp->name, name);
    tmp->height = 1;
    return tmp;
}
void insert(binaryTree **head, int key, char name[size])
{
    if (*head == NULL)
    {
        *head = newNode(key, name);
        return;
    }
    if ((*head)->key < key)
    {
        insert(&(*head)->right, key, name);
    }
    else if ((*head)->key > key)
    {
        insert(&(*head)->left, key, name);
    }
    else
    {
        printf("Aynı Coda izin verilmez\n");
        return;
    }
    (*head)->height = 1 + height(*head);
}
binaryTree *rightRotate(binaryTree *y)
{
    binaryTree *x = y->left;
    binaryTree *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
binaryTree *leftRotate(binaryTree *x)
{
    binaryTree *y = x->right;
    binaryTree *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
binaryTree *insertAvl(binaryTree *head, int key, char name[size])
{
    if (head == NULL)
    {

        return newNode(key, name);
    }
    if ((head)->key < key)
    {
        (head)->right = insertAvl((head)->right, key, name);
    }
    else if ((head)->key > key)
    {
        head->left = insertAvl((head)->left, key, name);
    }
    else
    {
        printf("Aynı Coda izin verilmez\n");
        return head;
    }
    (head)->height = 1 + height(head);

    int balance = getBalance(head);

    if (balance > 1 && key < head->left->key)
        return rightRotate(head);

    if (balance < -1 && key > head->right->key)
        return leftRotate(head);

    if (balance > 1 && key > head->left->key)
    {
        head->left = leftRotate(head->left);
        return rightRotate(head);
    }

    if (balance < -1 && key < head->right->key)
    {
        head->right = rightRotate(head->right);
        return leftRotate(head);
    }
    return head;
}
int getBalance(binaryTree *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

void inorder(binaryTree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d: %s ->", root->key, root->name);
        inorder(root->right);
    }
}

void preorder(binaryTree *root)
{
    if (root != NULL)
    {
        printf("%d:%s > ", root->key, root->name);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(binaryTree *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d : %s \n", root->key, root->name);
    }
}
binaryTree *findMin(binaryTree *root)
{
    binaryTree *min = root;
    if (root->left != NULL)
    {
        min = findMin(root->left);
    }
    return min;
}
binaryTree *findMax(binaryTree *root)
{
    binaryTree *max = root;
    if (root->right != NULL)
    {
        max = findMax(root->right);
    }
    return max;
}
binaryTree *deleteAvl(binaryTree *root, int item)
{

    if (root == NULL)
    {
        printf("List dont contain: %d\n", item);
        return root;
    }
    if (item < root->key)
    {
        root->left = deleteAvl(root->left, item);
    }
    else if (item > root->key)
    {
        root->right = deleteAvl(root->right, item);
    }
    else
    {
        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            binaryTree *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            free(temp);
        }
        else
        {
            binaryTree *tmp = findMin(root->right);
            root->key = tmp->key;
            root->right = deleteNodeByItem(root->right, tmp->key);
        }
    }
    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
binaryTree *deleteNodeByItem(binaryTree *root, int item)
{

    if (root == NULL)
    {
        printf("List dont contain: %d", item);
        return root;
    }
    if (item < root->key)
    {
        root->left = deleteNodeByItem(root->left, item);
    }
    else if (item > root->key)
    {
        root->right = deleteNodeByItem(root->right, item);
    }
    else
    {
        if (root->left == NULL)
        {
            binaryTree *tmp = root->right;
            free(root);
            return tmp;
        }
        else if (root->right == NULL)
        {
            binaryTree *tmp = root->left;
            free(root);
            return tmp;
        }

        binaryTree *tmp = findMin(root->right);
        root->key = tmp->key;
        root->right = deleteNodeByItem(root->right, tmp->key);
    }

    return root;
}
int height(binaryTree *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int lhg = height(root->left);
        int rhg = height(root->right);
        if (lhg > rhg)
            return (lhg + 1);
        else
        {
            return (rhg + 1);
        }
    }
}
void levelorder(binaryTree *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        currentLevel(root, i);
}
void currentLevel(binaryTree *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        printf("%d : %s\n", root->key, root->name);
    }
    else if (level > 1)
    {
        currentLevel(root->left, level - 1);
        currentLevel(root->right, level - 1);
    }
}