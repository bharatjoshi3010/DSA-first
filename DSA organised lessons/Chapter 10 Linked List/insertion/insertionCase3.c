#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedListTreverse(struct Node *p){
    while(p!= NULL){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

void insertEnd(struct Node *head, int value){
    struct Node *ptr = (struct Node *)malloc(sizeof (struct Node));
    struct Node *p = head;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    
    p->next=ptr;
    ptr->next =NULL;
    ptr->data = value;
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
    insertEnd(head, 345);
    linkedListTreverse(head);
    return 0;
}