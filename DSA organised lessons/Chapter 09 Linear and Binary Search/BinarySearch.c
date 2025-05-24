#include <stdio.h>
int bSearch(int a[], int uSize, int element){
    int low, high, mid;
    low=0;
    high = uSize-1;
    
    while (low<=high)
    {
        mid = (low+high)/2;
        if(a[mid]==element){
            return mid;
        }
        else if(element>a[mid]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[100]={50,55,65,89,101,560,890,896,910,972,989};
    int find = bSearch(arr, 11,989);
    printf("The location of searched elment is %d", find);
    return 0;
}