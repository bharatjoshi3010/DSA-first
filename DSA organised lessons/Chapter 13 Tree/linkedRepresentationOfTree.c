#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * left;
    struct Node * right;
}node;

node * createNode(int value){
    node * n = (node *)malloc(sizeof(node));
    n->data = value;
    n->left =NULL;
    n->right = NULL;
    return n;
}

int main()
{
    node * root = createNode(50);
    node * n1 = createNode(70);
    node * n2 = createNode(90);
    node * n3 = createNode(22);
    node * n4 = createNode(15);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n2->right = n4;        
    return 0;
}