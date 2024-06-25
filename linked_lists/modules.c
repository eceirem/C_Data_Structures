#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *creat_list(struct node *start)
{
    struct node *new_node, *ptr;
    int value;
    printf("Please enter the value: (-1 to end.)");
    scanf("%d", &value);
    while (value != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = value;

        if (start == NULL)
        {
            start = new_node;
            new_node->next = NULL;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL) // Eğer bunu yazmazsan liste hep 2 elemanlı oluyor. null elemanına eşit değilken o kadar yer zaten dolu demek amacım sona eklemek bu yüzden null görene kadar ilerlemem lazım.
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
        }
        printf("Please enter the value: (-1 to end.)");
        scanf("%d", &value);
    }
    return start;
}
void display(struct node *start)
{
    struct node *ptr = start;
    int i = 0;
    while (ptr != NULL)
    {
        i++;
        printf("%d. eleman %d\n", i, ptr->data);
        ptr = ptr->next;
    }
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
        new_node->next = start;
        start = new_node;
        return start;
    case 2:
        ptr = start;
        new_node->next = NULL;
        while (ptr->next != NULL)
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
        start = start->next;
        free(ptr);
        return start;
    case 2:
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
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
    struct node *start = NULL;
    int ope;
    printf("1-Creat the list.\n2-Insert element.\n3-Delete element.\n");
    printf("Please enter the number of operation which you wanted (-1 to end.): ");
    scanf("%d", &ope);
    while (ope != -1)
    {
        switch (ope)
        {
        case 1:
            start = creat_list(start);
            break;
        case 2:
            start = insert(start);
            break;
        case 3:
            start = delete (start);
            break;
        default:
            break;
        }
        display(start);
        printf("1-Creat the list.\n2-Insert element.\n3-Delete element.\n");
        printf("Please enter the number of operation which you wanted:(-1 to end.) ");
        scanf("%d", &ope);
    }
}