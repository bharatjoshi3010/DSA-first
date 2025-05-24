//for deleting first element in the linklist
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void llTraversal(struct Node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node * delFromStart(struct Node *head){
    struct Node * ptr = head;  //we have to do it to avoid memory leaks
    head = head->next;
    free(ptr);
    return head;
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
    llTraversal(head);
    head = delFromStart(head);
    llTraversal(head);
    return 0;
}