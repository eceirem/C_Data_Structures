#include <stdio.h>

int main(){
    int arr[10], i, n, *ptr1, *ptr2;
    printf("Please enter the number of array: ");
    scanf("%d",&n);
    printf("Please enter the elements of array: ");
    for (int i = 0; i < n; i++)
    {
        printf("\n arr[%d] =  ", i);
        scanf("%d", &arr[i]);
    }    
    ptr1 = &arr[0];
    ptr2 = &arr[n-1];
    while (ptr1 <= ptr2)
    {
        printf("%d\n", *ptr1);
        ptr1++;
    }
}