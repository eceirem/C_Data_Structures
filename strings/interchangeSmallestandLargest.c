#include <stdio.h>
int smallest(int arr[],int n);
int largest(int arr[], int n);
void print_array(int arr[], int n);
void interchange(int arr[], int n);
void get_array(int arr[], int n);

int main(){
    int arr[10], i, n;
    printf("Please enter the number of array: ");
    scanf("%d",&n);
    printf("Please enter the elements of array: ");
    get_array(arr,n);
    interchange(arr,n);
    printf("The new array is: \n");
    print_array(arr,n);
    return 0;
}

void get_array(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("\n arr[%d] =  ", i);
        scanf("%d", &arr[i]);
    }    
}

void print_array(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }    
}

int smallest(int arr[],int n){
    int smallest, i, index = 0;
    smallest = arr[0];
    for (i = 1; i < n; i++)
    {
        if(arr[i]<smallest){
            smallest = arr[i];
            index = i;
        }
    }
    return index;    
}
int largest(int arr[],int n){
    int largest, i, index = 0;
    largest = arr[0];
    for (i = 1; i < n; i++)
    {
        if(arr[i]>largest){
            largest = arr[i];
            index = i;
        }
    }
    return index;    
}

void interchange(int arr[], int n){
    int temp,small,large;
    small = smallest(arr,n);
    large = largest(arr,n);
    temp = arr[small];
    arr[small] = arr[large];
    arr[large] = temp;
}


