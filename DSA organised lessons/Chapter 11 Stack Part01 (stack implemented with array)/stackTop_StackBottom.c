#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int top;
    int size;
    int *arr;
}stack;

int isEmpty(stack *a){
    if(a->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(stack *a){
    if(a->top == a->size -1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(stack *a, int info){
    if(!isFull(a)){
        a->top++;
        a->arr[a->top]=info;
        printf("Push Operation Successfull\n");
    }
    else{
        printf("push operation failed\n");
    }

}
int pull(stack *a){
    if(!isEmpty(a)){
        int info = a->arr[a->top];
        a->top--;
        
        printf("Pull Operation Successfull\n");
        return info;
    }
    else{
        printf("pull operation failed\n");
    }

}
void top(stack * a){
    printf("%d ", a->arr[a->top]);
}
void bottom(stack *a){
    printf("%d ", a->arr[0]);
}
int main()
{
    stack * s2;
    s2 = (stack *)malloc(sizeof(stack));
    s2->top = -1;
    s2->size = 10;
    s2->arr = (int *)malloc(sizeof(int)*s2->size);
    push (s2, 06);
    push(s2, 72);
    push(s2, 45);
    push(s2, 78);
    push(s2, 01);
    pull(s2);
    top(s2); // tell the top most element of the stack
    bottom(s2); // tell the bottom element of the stack
    return 0;
}