#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * right;
    struct Node * left;
}node;

node * createNode(int value){
    node * new = (node *)malloc(sizeof(node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void preorder(node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postOrder(node * root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(node *root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data );
        inOrder(root->right);
    }
}

int main()
{
    node * root = createNode(50);
    node * p1 = createNode(55);
    node * p2 = createNode(12);
    node * p3 = createNode(25);
    node * p4 = createNode(78);
    node * p5 = createNode(36);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;

    preorder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    inOrder(root);
    return 0;
}