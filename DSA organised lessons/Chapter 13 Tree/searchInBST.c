#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
} node;

node *createNode(int value)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

int isBst(node *root)
{ // is binary search tree??
    static node *prev = NULL;
    if (root != NULL)
    {
        if (!isBst(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBst(root->right);
    }
    else
    {
        return 1;
    }
}

int searchBst(node *root, int value)
{
    while (root!=NULL)
    {
        if (root->data < value)
        {
            root = root->right;
        }
        else if (root->data > value)
        {
            root = root->left;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    node *root = createNode(100);
    node *p1 = createNode(80);
    node *p2 = createNode(120);
    node *p3 = createNode(70);
    node *p4 = createNode(90);
    node *p5 = createNode(130);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    printf("is the given tree is a binary tree : %d\n", isBst(root));
    printf("is 45 present in the tree : %d\n", searchBst(root, 90));
    return 0;
}