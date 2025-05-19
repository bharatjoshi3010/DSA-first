#include <stdio.h>
#include <stdlib.h>

//stack ADT
typedef struct Stack
{
    int size;
    int top;
    int *arr;
}stack;

//isEmpty (checking underflow)
int isEmpty(stack *a){
    if(a->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

//isFull (Checking Overflow)
int isFull(stack *a){
    if(a->top==a->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

//push(insertion on stack)
void push(stack *a, int value){
    if(!isFull(a)){
        a->top +=1;
        a->arr[a->top] = value;
        printf("push succesfull\n");
    }
    else{
        printf("push failed\n");
    }
}

//pop(deletion from stack)
int pop(stack * a){
    if(!isEmpty(a)){
        int temp = a->arr[a->top];
        a->top -= 1;
        return temp;
    }
    else{
        printf("pop operation failed \n");
        return 0;
    }
}

//it starts cuonting of the elements from the bottom
void peakFromBottom(stack * a, int position){
    printf("the %dth element from the bottom is %d\n", position, a->arr[position-1]);
    
}

//it starts counting the elements from above
void peakFromAbove(stack * a, int position){
    printf("the %dth element from the top is %d\n", position, a->arr[a->top+1-position]);
    
}

//it starts printing from above to below
void peak(stack* a){
    if(!isEmpty(a)){
        printf("The elements in the stack are : ");
        for(int i = a->top; i>=0; i--){
            printf("%d ", a->arr[i]);
        }
        printf("\n");
    }

    else{
        printf("Stack is empty");
    }
}

int main()
{
    stack *s1=(stack *)malloc(sizeof(stack));
    s1->top=-1;
    s1->size = 10;
    s1->arr =  (int *)malloc(sizeof(int)*s1->size);
    printf("is satck empty before : %d\n", isEmpty(s1));
    printf("is satck full before : %d\n", isFull(s1));
    push(s1, 50);
    push(s1, 545);
    push(s1, 64564);
    push(s1, 5455);
    push(s1, 45);
    push(s1, 313);
    push(s1, 458);
    push(s1, 789);
    push(s1, 321);
    push(s1, 879);
    push(s1, 63); //stack is full so this push operation get failed. 
    printf("is stack empty after insertion : %d\n", isEmpty(s1));
    printf("is stack full after insertion : %d\n", isFull(s1));
    printf("%d\n", pop(s1));
    printf("%d\n", pop(s1));
    push(s1, 63);
    printf("%d\n", pop(s1));
    push(s1, 572);
    peak(s1);
    
    peakFromAbove(s1,3);
    peakFromBottom(s1, 3);
    return 0;
}