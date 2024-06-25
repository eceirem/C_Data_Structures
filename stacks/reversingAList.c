#include <stdio.h>

int stack[10], top = -1;

int pop();
void push(int);

void push(int val)
{
    stack[++top] = val;
}

int pop()
{
    return (stack[top--]);
}

int main()
{
    int arr[10], i, n, val;
    printf("Enter the number of elements in the array:");
    scanf("%d", &n);
    printf("Enter the elements of the array \n");
    for (i = 0; i < n; i++)
    {
        printf("Eleman:");
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        push(arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        val = pop();
        arr[i] = val;
    }
    printf("The reversed array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
