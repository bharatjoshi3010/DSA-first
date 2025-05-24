#include <stdio.h>
int delete(int arr[], int size, int index){
        for(int i = index; i<size; i++){
            arr[i] = arr[i+1];
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
    delete(a, 4, 0);
    display(a, 4);
    return 0;
}