#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *back;
}node;

void traversal(node * a){
    while(a!=NULL){
        printf("%d ", a->data);
        a=a->next;
    }
    printf("\n");
}

node * insertAtFirst(node * head, int value){
    node * new = (node *)malloc(sizeof(node)); 
    new->back=NULL;
    new->data=value;
    new->next=head;
    head->back=new;
    head = new;
    return head;

}

int main()
{
    node * head = (node *)malloc(sizeof(node));
    node * first = (node *)malloc(sizeof(node));
    node * second = (node *)malloc(sizeof(node));
    node * third = (node *)malloc(sizeof(node));
    node * fourth = (node *)malloc(sizeof(node));
    node * fifth = (node *)malloc(sizeof(node));
    head->data = 50;
    first->data = 55;
    second->data = 78;
    third->data = 12;
    fourth->data = 99;
    fifth->data = 42;

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    head->back = NULL;
    first->back = head;
    second->back = first;
    third->back = second;
    fourth->back = third;
    fifth->back = fourth;
    
    traversal(head);
   head= insertAtFirst(head, 66);
    traversal(head);

    return 0;
}