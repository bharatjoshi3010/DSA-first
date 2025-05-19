#include <stdio.h>
#include<stdlib.h>

struct myArray
{
    int totalSize;
    int usedSize;
    int * ptr;
};
void createArray(struct myArray * a, int tSize, int uSize){
    a->ptr=(int *)malloc(tSize * sizeof(int));
    a->totalSize = tSize;
    a->usedSize = uSize;
}
void setValue(struct myArray * a){
    for (int i = 0 ; i<a->usedSize; i++){
        printf("Enter element %d : ", i+1);
        scanf("%d", &(a->ptr[i]));
    }
}
void getValue(struct myArray * a){
    for (int i =0 ; i<a->usedSize;i++){
        printf("the elemnt %d is : %d ", i+1, (a->ptr)[i]);
    }
}


int main()
{
    struct myArray obj1;
    createArray(&obj1, 10, 4);
    setValue(&obj1);
    getValue(&obj1);
    return 0;
}