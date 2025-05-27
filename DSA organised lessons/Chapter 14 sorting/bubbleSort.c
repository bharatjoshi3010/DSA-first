#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int * arr, int size){
    int isSorted =0 ;
    for(int i =size-1 ; i>=0; i--){
        isSorted =1;
        for(int j = 0; j<=i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted =0;
            }
        }
        if(isSorted == 1){
            printf("array get sort in %d th itteration \n", size-i);
            return;
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
    BubbleSort(arr, 10);
    printArray(arr, 10);
    int arr1[8] = {1,2,3,4,5,6,7,8};
    printArray(arr1, 8);
    BubbleSort(arr1, 8);
    printArray(arr1, 8);
    return 0;
}