#include <stdio.h>
#include <stdlib.h>

void insertionSort(int * arr, int size){

    for (int i = 1; i<size; i++){
        for(int j = i; j>0; j--){
            if(arr[j-1]>arr[j]){
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }else{
                break;
            }
        }
    }
}

void printArray(int * arr, int size){
    for(int i=0; i<size; i++){
        printf ("%d ", arr[i]); 
    }
    printf("\n");
}

int main()
{
    int arr[10] = {10,40,55,88,96,78,12,36,56,9};
    printArray(arr, 10);
    insertionSort(arr, 10);
    printArray(arr, 10);
    // int arr1[8] = {1,2,3,4,5,6,7,8};
    // printArray(arr1, 8);
    // BinarySort(arr1, 8);
    // printArray(arr1, 8);
    return 0;
}