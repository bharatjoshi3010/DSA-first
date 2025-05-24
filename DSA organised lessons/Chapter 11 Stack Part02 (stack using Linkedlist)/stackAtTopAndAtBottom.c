#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;  
}node;

node * push(node* top, int value){
    node * new = (node* )malloc(sizeof(node));
    if(new == NULL){
        printf("Stack Overflow");
        return top;
    }else{
        new->data = value;
        new->next = top;
        top = new;
        printf("push successful\n");
        return top;
    }
}
int pull(node **top){
    if(*top == NULL){
        printf("Stack Underflow");
    }
    else{
        node* temp = *top;
        int temp1 = temp->data;
        *top = (*top)->next;
        return temp1;
    }
}
void peek(node* top){
    node* temp = top;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int top(node* top){
    return top->data;
}
int bottom(node* top){
    node * temp = top;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    return temp->data;
}

int main()
{
    node* n1=NULL;
    n1 = push(n1, 55);
    n1=push(n1, 750);
    n1=push(n1, 789);
    n1=push(n1, 421);
    peek(n1);
    pull(&n1);
    n1=push(n1, 545);
    peek(n1);
    printf("the top element of the stack is %d\n",top(n1));
    printf("the bottom most element of the stack is %d\n",bottom(n1));
    return 0;
}