#include<stdio.h>
#include<stdlib.h>
struct myArray{
    int totalSize;
    int usedSize;
    int * ptr;
};
void createArray(struct myArray *a, int tSize, int uSize){
    a->ptr = (int *)malloc(tSize * sizeof(int));
    a->totalSize = tSize;
    a->usedSize = uSize;
}

void setValue(struct myArray *a){
    for(int i=0; i<a->usedSize; i++){
        printf("Enter the value of %d element : ", i);
        scanf("%d", &(a->ptr[i]));
    }
}
void getValue(struct myArray *a){
    for(int i=0; i<a->usedSize; i++){
        printf("The value of %d element is: %d \n", i, (a->ptr[i]));
    }
}
void insert(struct myArray *a, int index, int value){
    if(a->totalSize==a->usedSize){
        printf("array is full no insertion is possible");
    }
    else if (index>=a->totalSize){
        printf("index out of memory");
    }
    else if(index>=a->usedSize){
        a->ptr[index]=value;
        a->usedSize++;
    }
    else{
        for(int i=(a->usedSize);i>=index;i--){
            a->ptr[i]=a->ptr[i-1];
        }
        a->ptr[index] = value;
        a->usedSize++;
    }
}
void main(){
    struct myArray obj;
    createArray(&obj,10,10);
    setValue(&obj);
    getValue(&obj);
    insert(&obj,11,789 );
    getValue(&obj);
}