#include <stdio.h>
#include <stdlib.h>

void printA(int * arr, int size){
    for(int i =0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int * arr, int size){
    for(int i=0; i<size; i++){
        int min = i;
        for(int j = i; j<size; j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr [i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[8] = {21,25,45,85,74,12,36,56};
    printA(arr,8);
    selectionSort(arr, 8);
    printA(arr, 8);
    return 0;
}