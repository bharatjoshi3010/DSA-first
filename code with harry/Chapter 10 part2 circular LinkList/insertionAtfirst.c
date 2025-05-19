#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void cllTreversal(struct Node *head){
    struct Node *ptr = head;
    do{
        printf("%d ", head->data);
        head = head->next;
    }while(head != ptr);
    printf("\n");
    free(ptr);
}

struct Node * atFirst(struct Node *head, int value){
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data=value;
    struct Node *ptr = head;
    new->next = head;
    do{
        head=head->next;
    }while(head->next !=ptr);
    head->next=new;
    return new;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    head->data = 55;
    first->data = 65;
    second->data = 45;
    third->data = 35;
    head->next =  first;
    first->next =  second;
    second->next =  third;
    third->next =  head;
    cllTreversal(head);
    head = atFirst(head,23);
    cllTreversal(head);
    return 0;
}