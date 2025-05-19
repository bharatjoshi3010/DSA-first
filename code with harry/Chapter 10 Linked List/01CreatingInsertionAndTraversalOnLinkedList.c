#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third;
    struct Node *fourth;
    struct Node *intruder; 
    // printf("%d", sizeof(struct Node));
    head= (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    intruder = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    
    head->data = 7;
    head->next = second;
    second->data= 41;
    second->next = third;
    third->data=72;
    third->next = intruder;
    intruder->data=8956;
    intruder->next=fourth;
    fourth->data=66;
    fourth->next = NULL;

    linkedListTraversal(head);
    return 0;
}