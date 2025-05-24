#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int size;
    int back;
    int front;
    int * arr;
}Queue;

int isFull(Queue* q1){
    if(q1->back == q1->size-1){
        return 1;
    }return 0;
}
int isEmpty(Queue* q1){
    if(q1->back==q1->front){
        return 1;
    }return 0;
}
void enqueue(Queue* q1,int value){
    if(!isFull(q1)){
        q1->back++;
        q1->arr[q1->back] = value;
    }else{
        printf("enqueue operation failed \n");
    }
}
int dequeue(Queue* q1){
    if(!isEmpty(q1)){
        q1->front++;
        return q1->arr[q1->front];
    }else{
        printf("dequeue operation failed \n");
        return -1;
    }
}
void display(Queue * q1){
    for(int i = q1->front+1; i<= q1->back; i++){
        printf("%d ",q1->arr[i]);
    }
    printf("\n");
}

int main()
{
    Queue *q1 = (Queue *)malloc(sizeof(Queue));
    q1->back =-1;
    q1->front =-1;
    q1->size =10;
    q1->arr = (int *)malloc(sizeof(int)*q1->size);
    enqueue(q1, 72);
    enqueue(q1, 56);
    enqueue(q1, 45);
    enqueue(q1, 90);
    enqueue(q1, 40);
    enqueue(q1, 36);
    enqueue(q1, 96);
    enqueue(q1, 12);
    enqueue(q1, 72);
    enqueue(q1, 88);
    enqueue(q1, 98);//queue is alredy full can't add it
    display(q1);
    printf("let remove something : %d \n", dequeue(q1));
    display(q1);
    enqueue(q1, 420);
    display(q1);
    printf("let remove something : %d \n", dequeue(q1));
    display(q1);
    enqueue(q1, 780);//no matter we dequeueue or not once the queue is full it never accept the elements ever again
    display(q1);
    return 0;
}