#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int value){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n; 
}

int main(){
    struct Node * root = createNode(50);
    struct Node * n1 = createNode(50);
    struct Node * n2 = createNode(50);
    struct Node * n3  = createNode(50);
    root->left = n1;
    root->right = n2;
    n2->right = n3;

}