//insertion at the begining
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;    
    }
    printf("\n");
}

struct Node * linkedListInsert(struct Node *head, int value){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=value;
    ptr->next = head;
    return ptr;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    head->data=50;
    head->next=first;
    first->data=58;
    first->next=second;
    second->data=20;
    second->next=third;
    third->data=72;
    third->next=NULL;
    linkedListTraversal(head);
    struct Node * ptr = linkedListInsert(head,75);
    linkedListTraversal(ptr);


    return 0;
}