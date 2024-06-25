#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};
struct stack *top = NULL;
struct stack *pop(struct stack *);
struct stack *push(struct stack *, int val);
struct stack *display(struct stack *);
int peek(struct stack *);

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
            top = push(top, val);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            val = peek(top);
            if (val != -1)
            {
                printf("The value stored at the top of stack is %d\n", val);
            }
            else
            {
                printf("Stack is empty.");
            }
            break;
        case 4:
            top = display(top);
            break;
        }
    }
}

struct stack *push(struct stack *, int val)
{
    struct stack *ptr;
    ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->data = val;
    if (top == NULL) // ilk oluşturduğum düğüm, stack'deki ilk eleman
    {
        ptr->next = NULL;
        top = ptr;
    }
    else
    {
        ptr->next = top;
        top = ptr;
    }
    return top;
}
struct stack *pop(struct stack *)
{
    struct stack *ptr;
    ptr = top; // en baştan çıkarırım bu yüzden ilk elemanı tut.
    if (top == NULL)
    {
        printf("Stack Underflow.\n");
    }
    else
    {
        top = top->next;
        printf("The value being being popped is %d\n", ptr->data);
        free(ptr);
    }
    return top;
}

int peek(struct stack *top)
{
    if (top == NULL)
    {
        return -1;
    }
    else
    {
        return top->data;
    }
}

struct stack *display(struct stack *)
{
    struct stack *ptr;
    ptr = top;
    if (top == NULL)
    {
        printf("Stack is empty.");
    }
    else
    {
        while (ptr != NULL)
        {
            printf(" %d - ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
    return top;
}