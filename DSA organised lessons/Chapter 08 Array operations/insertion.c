#include <stdio.h>
int insert(int arr[], int size, int capacity, int index, int element){
    if(size>=capacity){
        printf("Insertion not possibel");
        return -1;
    }
    else{
        for(int i = size; i>=index; i--){
            arr[i] = arr[i-1];
        }
        arr[index] = element;
    }
}
void display(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
        
    }
    printf("\n");
}
int main()
{
    int a[50]={56,78,90,87};
    display(a, 4);
    insert(a, 4, 50, 1, 45);
    display(a, 5);
    return 0;
}