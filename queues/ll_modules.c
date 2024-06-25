#include <stdio.h>
#include <stdlib.h>
// struct yapısı ll için
struct node
{
    int data;
    struct node *next;
};
// q için sürekli front ve rear yazmaktansa bu şekilde ulaşabiliriz.
struct queue
{
    struct node *front;
    struct node *rear;
};
struct queue *q;
void create_queue(struct queue *);
struct queue *insert(struct queue *, int);
struct queue *delete_element(struct queue *);
struct queue *display(struct queue *);
int peek(struct queue *);

int main()
{
    int option, val;
    q = (struct queue *)malloc(sizeof(struct queue));
    create_queue(q);
    do
    {
        printf("*****MAIN MENU*****\n");
        printf("1-Insert element.\n2-Delete element.\n3-Peek\n4-Display the queue\n5-EXIT\n");
        printf("Please enter the number of operation which you wanted: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            int number;
            printf("Please enter the number to add queue: ");
            scanf("%d", &number);
            q = insert(q, number);
            break;
        case 2:
            q = delete_element(q);
            break;
        case 3:
            val = peek(q);
            if (val != 1)
            {
                printf("The first value in queue is: %d\n", val);
            }
            break;
        case 4:
            q = display(q);
            break;
        default:
            break;
        }
    } while (option != 5);
    return 0;
}

void create_queue(struct queue *)
{
    q->front = NULL;
    q->rear = NULL;
}

struct queue *insert(struct queue *, int x)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    if (q->front == NULL)
    {
        q->front = ptr;
        q->rear = ptr;
        q->front->next = NULL;
        q->rear->next = NULL;
    }
    else
    {
        q->rear->next = ptr; // bir önceki elemanın rear'ı ile bağlantı kuruyorum.
        q->rear = ptr;       // rear'ı ptr olarak güncelliyorum
        q->rear->next = NULL;
    }
    return q;
}
struct queue *delete_element(struct queue *)
{
    struct node *ptr;
    ptr = q->front; // ptr en başı gösteriyor şu an
    if (q->front == NULL)
    {
        printf("Underflow.\n");
    }
    else
    {
        q->front = q->front->next; // en baştan silme işlemi uyguladığım için front u bir sonrakine ata
        printf("The value being deleted is: %d\n", ptr->data);
        free(ptr);
    }
    return q;
}
struct queue *display(struct queue *)
{
    struct node *ptr;
    ptr = q->front; // starta eşitledim gibi düşün.
    if (ptr == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("o-|");
        while (ptr != q->rear)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\t", ptr->data);
    }
    printf("\n");
    return q;
}

int peek(struct queue *)
{
    if (q->front == NULL)
    {
        printf("Underflow.\n");
        return -1;
    }
    else
    {
        return q->front->data;
    }
}
