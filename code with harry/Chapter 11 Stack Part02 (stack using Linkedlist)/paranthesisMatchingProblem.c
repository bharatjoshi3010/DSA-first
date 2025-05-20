#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int top;
    int size;
    char *arr;
}stack;

int isEmpty(stack* s1){
    if(s1->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(stack * s1,char value){
    if(s1->top==(s1->size-1)){
        printf("stack overflow\n");
        exit;
    }else{
        s1->top++;
        s1->arr[s1->top]=value;
        printf("\npush succesful\n");
    }
}

char pull(stack* s1){
    if(isEmpty(s1)){
        printf("\nstack underflow\n");
        exit;
    }else{
        char temp = s1->arr[s1->top];
        s1->top--;
        printf("\npull successful\n");
        return temp;
    }
}

int valid(char ch[]){
    //you can make the stack in the main also but you have to pass it to this function
    stack* s1=(stack*)malloc(sizeof(stack));
    s1->size = 100;
    s1->top = -1;
    s1->arr = (char *)malloc(sizeof(char)*s1->size);
    int i=0;
    //this loop will work for paranthesis chacking
    while(ch[i]!='\0'){
        printf("%c ", ch[i]);
        if(ch[i]=='('){
            push(s1,'c');
        }
        else if (ch[i]==')')
        {
            if(isEmpty(s1)){
                printf("\ninvalid Exp(pull failed)\n");
                return -1;
            }else{
                pull(s1);
            }
        }  
        i++;  
    }
    if(isEmpty(s1)){
        printf("\nValid Exp\n");
        return 0;
    }else{
        printf("\ninvalid Exp (stack not empty till the last)\n");
        return -1;
    }
}

int main()
{
    
    char exp[] = "(50+80+90)(+100)";
    valid(exp);//this will check for parenthisis only it do not ensures correctness of the experission
    return 0;
} 