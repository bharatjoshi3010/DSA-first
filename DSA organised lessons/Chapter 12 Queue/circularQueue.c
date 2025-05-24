#include <stdio.h>
#include <stdlib.h>

typedef struct cqueue{
    int size;
    int front;
    int rear;
    int * arr;
}cQueue; 

int isFull(cQueue* cq1){
    if((cq1->rear+1)%cq1->size == cq1->front){
        return 1;
    }return 0;
}
int isEmpty(cQueue* cq1){
    if(cq1->rear == cq1->front){
        return 1;
    }return 0;
}

void enqueue(cQueue* cq1, int value){
    if(!isFull(cq1)){
        
        cq1->arr[cq1->rear] = value;
        cq1->rear = (cq1->rear +1)%cq1->size;
    }else{
        printf("Circular queue is full cant add more elements.\n");
    }
}

int dequeue(cQueue* cq1){
    if(!isEmpty(cq1)){
        int temp ;
        
        temp= cq1->arr[cq1->front];
        cq1->front = (cq1->front +1)%cq1->size;
        return temp;
    }else{
        printf("Circular queue is empty cant remove anything.\n");
        return -1;
    }
}

void peek(cQueue * cq1){
    for(int i = cq1->front; i!=cq1->rear; i=(i+1)%cq1->size){
        printf("element at %d postion is %d \n", i, cq1->arr[i]);
    }
}

int main()
{
    cQueue *cq1 = (cQueue *)malloc(sizeof(cQueue));
    cq1->front = 0;
    cq1->rear = 0;
    cq1->size = 10;
    cq1->arr = (int *)malloc(sizeof(int)*cq1->size);
    enqueue(cq1, 50);
    enqueue(cq1, 78);
    enqueue(cq1, 65);
    enqueue(cq1, 12);
    enqueue(cq1, 36);
    enqueue(cq1, 89);
    enqueue(cq1, 15);
    enqueue(cq1, 96);
    enqueue(cq1, 36);
    // enqueue(cq1, 72);  queue is full show it will show a overflow warning
    //--> Here the size of queue is 10 but it can store only 9 elements because we need one (front ) position free for the full empty condititon;
    peek(cq1);
    printf("the dequeued element is %d \n",dequeue(cq1));
    printf("the dequeued element is %d \n",dequeue(cq1));
    printf("the dequeued element is %d \n",dequeue(cq1));
    printf("the dequeued element is %d \n",dequeue(cq1));
    printf("the dequeued element is %d \n",dequeue(cq1));
    printf("the dequeued element is %d \n",dequeue(cq1));
    printf("the dequeued element is %d \n",dequeue(cq1));
    printf("the dequeued element is %d \n",dequeue(cq1));
    printf("the dequeued element is %d \n",dequeue(cq1));
    printf("the dequeued element is %d \n",dequeue(cq1));//it return -1 (error sign)
    enqueue(cq1, 77);
    enqueue(cq1, 72);
    enqueue(cq1, 13);
    // enqueue(cq1, 55);
    // enqueue(cq1, 796);  these two will show error (overflow warning);
    peek(cq1);
    return 0;
}