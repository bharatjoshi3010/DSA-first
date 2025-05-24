#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}node;
//we make it global varriable to avoid double pointers and a lot of mess(if we make it inside the main in dequeue enqueue we have to pass a '&' of f and r with '**')
node * f =NULL;
node * r = NULL;

int isEmpty(node* f){
    if(f == NULL){
        return 1;
    }return 0;
}

int isFull(node* r){
    node *n = (node *)malloc(sizeof(node));
    if(n==NULL){
        return 1;
    }return 0;
}

int linkedListTraversal(node * f){
    node * ptr = f;
    while (ptr != NULL){
        printf("the element is : %d \n", ptr->data);
        ptr=ptr->next;
    }
    printf("linked list traversal completed. \n\n");
}

node * enqueue(int value){
    if(!isFull(r)){
        node * new = (node *)malloc(sizeof(node));
        new->data = value;
        new->next = NULL;
        if(f == NULL){
            f=r=new;
        }else{
            r->next = new;
            r = new;
        }
    }else{
        printf("queue is full cant dequeue\n");
    }
    return r;
}

int dequeue(){
    int value =-1;
    if(!isEmpty(f)){
        value = f->data;
        f=f->next;
        return value;
    }else{
        printf("queue is empty cant dequeue \n");
    }
}

int main()
{
    linkedListTraversal(f);
    enqueue(54);
    enqueue(79);
    enqueue(9);
    enqueue(56);
    enqueue(12);
    enqueue(22);
    linkedListTraversal(f);

    printf("we dequeue the element : %d\n", dequeue());
    printf("we dequeue the element : %d\n", dequeue());
    printf("we dequeue the element : %d\n", dequeue());
    linkedListTraversal(f);
    printf("we dequeue the element : %d\n", dequeue());
    enqueue(402);
    linkedListTraversal(f);
    printf("we dequeue the element : %d\n", dequeue());
    printf("we dequeue the element : %d\n", dequeue());
    printf("we dequeue the element : %d\n", dequeue());

    return 0;
}