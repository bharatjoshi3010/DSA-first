#include <stdio.h>
int lSearch(int arr[], int uSize, int Element){
    for(int i = 0; i<uSize; i++){
        if(arr[i]==Element){
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[50]= {18,45,7,8,98,78,23,56,41};
    printf("the 23 is in %dth index", lSearch(arr, 9, 23));
    return 0;
}