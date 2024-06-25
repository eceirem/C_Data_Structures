#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void insert(void);
int delete_element(void);
int peek(void);
void display(void);

int main()
{
    int option, val;
    do
    {
        printf("1-Insert element.\n2-Delete element.\n3-Peek\n4-Display the queue\n5-EXIT\n");
        printf("Please enter the number of operation which you wanted: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            val = delete_element();
            if (val != 1)
            {
                printf("The number deleted is: %d\n", val);
            }
            break;
        case 3:
            val = peek();
            if (val != 1)
            {
                printf("The first value in queue is: %d\n", val);
            }
            break;
        case 4:
            display();
            break;
        default:
            break;
        }
    } while (option != 5);
    return 0;
}

void insert(void)
{
    int number;
    printf("Please enter the number to add queue: ");
    scanf("%d", &number);
    // yer yoksa
    if (rear == MAX - 1)
    {
        printf("Overflow.\n");
    }
    // ilk elemanı ekliyorsam
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = number;
    }
    else
    {
        queue[++rear] = number;
    }
}
int delete_element(void)
{
    int val;
    if (rear == -1 || front == -1 || front > rear)
    {
        printf("Underflow.");
    }
    else
    {
        val = queue[front];
        front++; // frontu arttırdım ama son elemanı silmiş olabilir miyim?
        if (front > rear)
        {
            front = rear = -1;
        }
        return val;
    }
}
int peek(void)
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue[front];
}
void display(void)
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("\nO|");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}