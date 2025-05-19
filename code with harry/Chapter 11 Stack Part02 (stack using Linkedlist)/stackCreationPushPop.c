#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

int isEmpty(node * top){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(node * top){
    node* n1 = (node *)malloc(sizeof(node));
    if(n1 == NULL){
    
        return 1;
    }
    else {
        free(n1);
        return 0;
    }

}

node * push(node * top, int value){
    node * new = (node*)malloc(sizeof(node));
    if(new == NULL){
        printf("Stack overflow can't push new elements");
    }else{
        new->data = value;
        new->next = top;
        top = new;
        printf("push succesfull \n");
        return top;
    }
    
    
}

int pop(node ** top){
    if(isEmpty(*top)){
        printf("Stack underflow can't pull");
        return -1;
    }else{
        node* new =*top;
        int pop = new->data;
        *top = (*top)->next;
        free(new);
        printf("pull Successful \n");
        return pop;
    }
    printf("\n");
}
void peek(node *top){
    node* peek = top;
    while(peek != NULL){
        printf("%d ", peek->data);
        peek = peek->next;
    }
    printf("\n");
}
// int peekAtPos(node *top, int pos){
//     node * ptr = top;
//     for(int i=1; i<pos;i++){
//         if(ptr == NULL){
//             printf("Invalid position\n");
//             return ptr->data;
//         }else{
//             ptr = ptr->next;
//         }
//     }
//     if(ptr==NULL){
//             printf("Invalid position");
//             return -1;
//         }else{
//             return ptr->data;
//         }
// }
//this fuction can be written as ----->
int peekAtPos(node * top, int pos){
    node * peek = top;
    for (int i=1; i<pos && peek->next!=NULL; i++ ){
        peek = peek->next;
    }
    return peek->data;
    //in this if position goes out of bound it will return the last nodes data 
}
int main()
{
    node *n1=NULL;
    n1 = push(n1, 50);
    n1 = push(n1, 56);
    n1 = push(n1, 72);
    n1 = push(n1, 25);
    n1 = push(n1, 45);
    n1 = push(n1, 63);
    peek(n1);
    printf("the element in 4th position is %d\n", peekAtPos(n1,4));
    pop(&n1);
    pop(&n1);
    peek(n1);
    printf("Now the element in 4th position is %d\n", peekAtPos(n1,4));
    return 0;
}