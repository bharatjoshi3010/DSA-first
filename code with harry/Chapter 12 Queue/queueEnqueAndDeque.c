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
    if(q1->back == q1->size-1 && q1->front == -1){
        return 1;
    }return 0;
}
int isEmpty(Queue* q1){
    if(q1->back==-1 && q1->front == -1){
        return 1;
    }return 0;
}
void enque(Queue* q1,int value){
    if(!isFull(q1)){
        q1->back++;
        q1->arr[q1->back] = value;
    }else{
        printf("enqueue operation failed \n");
    }
}
int deque(Queue* q1){
    if(!isEmpty(q1)){
        q1->front++;
        return q1->arr[q1->front];
    }else{
        printf("dequeue operation failed \n");
    }
}
void peek(Queue * q1){
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
    enque(q1, 72);
    enque(q1, 56);
    enque(q1, 45);
    enque(q1, 90);
    enque(q1, 40);
    enque(q1, 36);
    enque(q1, 96);
    enque(q1, 12);
    enque(q1, 72);
    enque(q1, 88);
    enque(q1, 98);//queue is alredy full can't add it
    peek(q1);
    printf("let remove something : %d \n", deque(q1));
    peek(q1);
    enque(q1, 420);
    peek(q1);
    printf("let remove something : %d \n", deque(q1));
    peek(q1);
    enque(q1, 780);
    peek(q1);
    return 0;
}