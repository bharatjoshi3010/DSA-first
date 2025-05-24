#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
void llTraversal(struct Node *head){
    while(head!=NULL){
        printf("%d ", head->data);
        head= head->next;
    }
    printf("\n");
}
void llDeleteLast(struct Node *head, int value){
    struct Node *ptr;
    while(head->data != value){
        ptr=head;
        head=head->next;
    }
    ptr->next=head->next;
    free(head);
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
    llDeleteLast(head,56);
    llTraversal(head);
    return 0;
}