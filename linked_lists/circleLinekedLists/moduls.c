#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void display(struct node *start)
{
    struct node *ptr = start;
    int i = 1;
    printf("%d. eleman %d\n", i, ptr->data);
    ptr = ptr->next;
    while (ptr != start)
    {
        i++;
        printf("%d. eleman %d\n", i, ptr->data);
        ptr = ptr->next;
    }
}

struct node *creat_cll(struct node *start)
{
    struct node *new_node, *ptr;
    int value;
    printf("Please enter the value(-1 to end.):");
    scanf("%d", &value);
    while (value != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = value;

        if (start == NULL)
        {
            start = new_node;
            new_node->next = start;
        }
        else
        {
            ptr = start;
            ptr = ptr->next;
            while (ptr->next != start) // Eğer bunu yazmazsan liste hep 2 elemanlı oluyor. null elemanına eşit değilken o kadar yer zaten dolu demek amacım sona eklemek bu yüzden start görene kadar ilerlemem lazım.
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = start;
        }
        printf("Please enter the value(-1 to end.):");
        scanf("%d", &value);
    }
    return start;
}
struct node *insert(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int value = 0, num, operator;
    printf("1-Insert begin.\n2-Insert end.\n3-Insert before.\n4-Insert after.\n");
    printf("Please enter the number which you want to do: ");
    scanf("%d", &operator);
    printf("Enter the data: ");
    scanf("%d", &value);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    switch (operator)
    {
    case 1:
        ptr = start;
        ptr = ptr->next;
        new_node->next = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        start = new_node;
        return start;
    case 2:
        ptr = start;
        new_node->next = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        return start;
    case 3:
        ptr = start;
        printf("Please enter the number insert before: ");
        scanf("%d", &num);
        while (ptr->data != num)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = new_node;
        new_node->next = ptr;
        return start;
    case 4:
        ptr = start;
        preptr = start;
        printf("Please enter the number insert after: ");
        scanf("%d", &num);
        while (preptr->data != num)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = new_node;
        new_node->next = ptr;
        return start;
    default:
        return start;
    }
}
struct node *delete(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int value = 0, num, operator;
    printf("1-Delete begin.\n2-Delete end.\n3-Delete element.\n4-Delete after.\n");
    printf("Please enter the operation number which you want to do: ");
    scanf("%d", &operator);
    ptr = start;
    preptr = start;
    switch (operator)
    {
    case 1:
        ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = start->next;
        free(start);
        start = ptr->next;
        return start;
    case 2:
        while (ptr->next != start)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = start;
        free(ptr);
        return start;
    case 3:
        printf("Please enter the number delete: ");
        scanf("%d", &num);
        while (ptr->data != num)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return start;
    case 4:
        printf("Enter the number after which the node has to deleted: ");
        scanf("%d", &num);
        while (preptr->data != num)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return start;
    default:
        return start;
    }
}

int main()
{
    struct node *start;
    int option;
    start = NULL;
    printf("*****MAIN MENU*****\n");
    printf("1.Create a list.\n2.Display the list.\n3.Insert an Element\n4.Delete an Element.\n5.EXIT\n");
    printf("Enter your option:");
    scanf("%d", &option);
    while (option != 5)
    {
        switch (option)
        {
        case 1:
            start = creat_cll(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            start = insert(start);
            break;
        case 4:
            start = delete (start);
            break;
        default:
            break;
        }
        printf("*****MAIN MENU*****\n");
        printf("1.Create a list.\n2.Display the list.\n3.Insert an Element\n4.Delete an Element.\n5.EXIT\n");
        printf("Enter your option:");
        scanf("%d", &option);
    }
}