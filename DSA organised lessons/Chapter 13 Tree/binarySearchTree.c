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
//in order of a binary search tree gives a increasing sequence
void inOrder(node *root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data );
        inOrder(root->right);
    }
}

int isBst(node * root){   //is binary search tree??
    static node * prev = NULL;
    if(root != NULL){
        if(!isBst(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBst(root->right);
    }else{
        return 1;
    }
}

int main()
{
    node * root = createNode(100);
    node * p1 = createNode(80);
    node * p2 = createNode(120);
    node * p3 = createNode(70);
    node * p4 = createNode(90);
    node * p5 = createNode(130);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;

   
    inOrder(root);
    printf("\n");
    printf("is the given tree is a binary tree : %d", isBst(root));
    return 0;
}