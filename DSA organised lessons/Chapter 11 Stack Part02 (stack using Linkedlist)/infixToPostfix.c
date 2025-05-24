#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
    int size;
    int top;
    char * arr;
}stack;

int isEmpty(stack * s1){
    if(s1->top == -1){
        return 1;
    }return 0;
}

int isFull(stack * s1){
    if(s1->top == s1->size-1){
        return 1;
    }return 0;
}

void push(stack * s1, char value){
    if(isFull(s1)){
        printf("stack is full cant push");
        exit(-1);

    }   else{
        s1->top++;
        s1->arr[s1->top] = value;
    } 
}

char pull(stack * s1){
    if(isEmpty(s1)){
        printf("stack is empty can't pull");
        return '\0';
    }else{
        char temp = s1->arr[s1->top];
        s1->top--;
        return temp;
    }
}

int isOperator(char a){
    if((a=='+') || (a=='-') || (a=='*')||(a=='/')){
        return 1;
    }
    return 0;
}

int presedence(char a){
    if((a=='+') || (a=='-')){
        return 1;
    }else if ((a=='*') || (a=='/'))
    {
        return 2;
    }
    
    return 0;
}

void infixToPostfix(char exp[]){
    int i=0;
    stack * s1 = (stack *)malloc(sizeof(stack));
    s1->top=-1;
    s1->size = strlen(exp);
    s1->arr = (char *)malloc(sizeof(char)*s1->size);
    while(exp[i]!='\0'){
        if(isOperator(exp[i])){
            if(isEmpty(s1)){
                push(s1, exp[i]);
            }else if(presedence(exp[i])<=presedence(s1->arr[s1->top])){
                while(presedence(exp[i])<=presedence(s1->arr[s1->top])){
                    printf("%c", pull(s1));
                }
                push(s1, exp[i]);
            }else{
                push(s1, exp[i]);
            }
        }else{
            printf("%c",exp[i] );
        }
        i++;
    }
    while(!isEmpty(s1)){
        printf("%c", pull(s1));
    }
}

int main()
{
    char infix[] ="x-y/z+k*a";
    infixToPostfix(infix);
    return 0;
}