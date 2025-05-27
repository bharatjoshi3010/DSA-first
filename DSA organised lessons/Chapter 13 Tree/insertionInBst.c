#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * left;
    struct Node * right;
}node;

node * createNode(int value){
    node* new = (node *)malloc(sizeof(node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void inorder(node * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void insert(node * root, int value){
    node * prev = NULL;
        while (root!=NULL)
        {
            if (root->data == value)
            {
                printf("%d is already exist in the tree how can i insert???");
                return;
            }else if (root->data < value)
            {
                prev = root;
                root= root->right;
            }else{
                prev = root;
                root = root->left;
            }
        }
        node * new = createNode(value);
        if(value<prev->data){
            prev->left = new;
        }else{
            prev->right = new;
        }
        
     }

int main(){
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
    inorder(root);
    printf("\n");
    insert(root, 85);
    insert(root, 100);
    printf("\n");
    inorder(root);
    return 0;
}