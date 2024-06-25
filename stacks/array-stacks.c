#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX], top = -1;
int pop(int stack[]);
int peek(int stack[]);
void push(int stack[], int val);
void display(int stack[]);
int main()
{
    int ope = 0, val;
    while (ope != 5)
    {
        printf("*****MAIN MENU*****\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.EXIT\n");
        printf("Please enter your option:");
        scanf("%d", &ope);
        switch (ope)
        {
        case 1:
            printf("Please enter the value to be pushed on stack:");
            scanf("%d", &val);
            push(stack, val);
            break;
        case 2:
            val = pop(stack);
            if (val != -1)
            {
                printf("The value popped from stack is %d", val);
            }
            printf("\n");
            break;
        case 3:
            val = peek(stack);
            if (val != -1)
            {
                printf("The value stored at the top of stack is %d", val);
            }
            printf("\n");
            break;
        case 4:
            display(stack);
            break;
        default:
            break;
        }
    }
}
int pop(int stack[])
{
    int val;
    if (top == -1)
    {
        printf("Stack Underflow.\n");
        return -1;
    }
    else
    {
        val = stack[top];
        top--;
        return val;
    }
}
int peek(int stack[])
{
    int val;
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    else
    {
        val = stack[top];
        return val;
    }
}
void push(int stack[], int val)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow.\n");
    }
    else
    {
        stack[++top] = val;
    }
}
void display(int stack[])
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        for (int i = top; i >= 0; i--) // sondan başa doğru gideriz bu yüzden max değer ile başlamalı
        {
            printf("%d\n", stack[i]);
        }
    }
}