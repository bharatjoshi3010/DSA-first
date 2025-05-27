#include <stdio.h>

void printArr(int *arr, int size){
    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void countSort(int *arr, int size){
    int max = 0;
    for(int i =0 ; i<size; i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }
    max=max+1;
    int newArr[max];
    for(int i = 0; i<max; i++){
        int count = 1;
        int avl =0;
        for(int j=0; j<size; j++){

            if(arr[j]==i){
                newArr[i] = count;
                avl = 1;
                count++;
            }
        }
        if(avl == 0){
            newArr[i]=0;
        }
    }
    printArr(newArr, max);
    int i =0;
    int j=0;
    while(i<max){
        if(newArr[i]==0){
            i++;
            continue;
        }else{
            arr[j]=i;
            j++;
            newArr[i]--;
        }
    }
}

int main()
{
    int arr[10]= {1,3,7,9,8,5,4,2,1,1};
    printArr(arr, 10);
    countSort(arr, 10);
    printArr(arr, 10);
    return 0;
}