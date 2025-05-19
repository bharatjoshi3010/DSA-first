#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
void llTraversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
struct Node * deletelast(struct Node *head){
    struct Node *p= head;
    struct Node *q= head->next;
    while(q->next != NULL){
        p=p->next;
        q=q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    head->data =  56;
    first->data =  45;
    second->data = 89;
    third->data = 78;
    fourth->data = 66;
    head->next=first;
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=NULL;
    llTraversal(head);
    deletelast(head);
    llTraversal(head);
    return 0;
}