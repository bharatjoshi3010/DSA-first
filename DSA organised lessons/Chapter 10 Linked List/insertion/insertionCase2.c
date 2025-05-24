#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node * insertInBW(struct Node *head, int index, int value){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));//this is the new Node
    struct Node *p = head; //we make it equal to the head because by doing this we can do traversing.
    int i=0;
    while(i!=index-1){

        p=p->next;
        i++;
    }
    ptr->next=p->next;
    ptr->data=value;
    p->next = ptr;
    return head;
}
void display(struct Node *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
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
    head = insertInBW(head, 3,3456);
    display(head);

    return 0;
}