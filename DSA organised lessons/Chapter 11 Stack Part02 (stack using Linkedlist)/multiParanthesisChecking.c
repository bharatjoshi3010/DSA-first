#include <stdio.h>
#include <stdlib.h>
#include<string.h> //for strlen function
typedef struct stack {
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
    if(s1->top == s1->size -1){
        return 1;
    }return 0;
}

void push(stack * s1, char value){
    if(isFull(s1)){
        printf("stack overflow");
    }else{
        s1->top++;
        s1->arr[s1->top] = value;
    }
}

char pop(stack * s1){
    if(isEmpty(s1)){
        printf("stack Underflow");
        return -1;
    }else{
        char temp = s1->arr[s1->top];
        s1->top--;
        return temp;
    }
}
int match(char a, char b){
    if((a=='(' && b==')')||(a=='{' && b=='}')||(a=='[' && b==']')){
        return 1;
    }
        return 0;
}

int valid(char exp[]){
    stack * s1 = (stack *)malloc(sizeof(stack));
    s1->size = strlen(exp);
    s1->top = -1;
    s1->arr = (char *)malloc(sizeof(char) * s1->size);
    int i=0;
    while(exp[i]!='\0'){
        if(exp[i] == '[' || exp[i] == '{' ||exp[i] == '('){
            if(isFull(s1)){
                printf("stack overflow can't do anyhthing");
                return -1;
            }else{
                push(s1, exp[i]);
            }
        }
        if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(isEmpty(s1)){
                printf("filed to pop (invalid exp)");
                return -1;
            }else{
                
                if(match(s1->arr[s1->top],exp[i])){
                    pop(s1);
                }else{
                    printf("Invalid Exp (parenthisis are not in right order)");
                    return 0;
                }
            }
        }
        i++;
        
    }
    if(isEmpty(s1)){
        printf("Valid exp");
        return 1;
    }else{
        printf("Stack is not clean(invalid exp)");
        return -1;
    }
}

int main()
{
    char * exp = "[50+7{30+20{56*(9)})]";
    valid(exp);

    return 0;
}