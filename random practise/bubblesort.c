#include <stdio.h>

int main()
{
    int a[]={30, 50, 90,45,12,34,104,3};
    for(int i=0; i<=7; i++){
        for(int j=0; j<7-i; j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        for(int i =0; i<=7; i++){
            printf("%d ", a[i]);
        } 
        printf("\n");
    }
     
    return 0;
}