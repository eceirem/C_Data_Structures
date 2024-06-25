#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char str_data[20];
    int priority;
    struct node *next;
};
struct node *start = NULL;
struct node *insert(struct node *, char str[]);
void display(struct node *);

int main()
{
    char string[100];
    while (1)
    {

        fgets(string, sizeof(string), stdin);

        // -1 kontrolü
        if (strcmp(string, "-1\n") == 0)
        {
            break;
        }

        start = insert(start, string);
    }
    display(start);
    return 0;
}

struct node *insert(struct node *start, char str[])
{
    int pri;
    struct node *new_node, *ptr, *prev;

    new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->str_data, str);

    // Priorite belirleme
    if ((strcmp("Annem\n", str) == 0) || (strcmp("Babam\n", str) == 0) || (strcmp("Kardesim\n", str) == 0))
    {
        printf("Kontrol");
        pri = 1;
    }
    else if (strcmp("Dayim\n", str) == 0 || strcmp("Teyzem\n", str) == 0 || strcmp("Amcam\n", str) == 0 || strcmp("Halam\n", str) == 0)
    {
        pri = 2;
    }
    else if (strcmp("Isyeri\n", str) == 0 || strcmp("Okul\n", str) == 0)
    {
        pri = 3;
    }
    else if (strcmp("Banka\n", str) == 0 || strcmp("Kargo\n", str) == 0)
    {
        pri = 5;
    }
    else if (strcmp("Reklam\n", str) == 0)
    {
        pri = 6;
    }
    else
    {
        pri = 4;
    }

    new_node->priority = pri;

    // Ekleme işlemi
    if ((start == NULL) || (pri < start->priority) || (pri == start->priority && strcmp(str, start->str_data) < 0))
    {
        new_node->next = start;
        start = new_node;
    }
    else
    {
        ptr = start;
        prev = NULL;

        while ((ptr != NULL) && ((pri > ptr->priority || (pri == ptr->priority && strcmp(str, ptr->str_data) > 0))))
        {
            prev = ptr;
            ptr = ptr->next;
        }

        new_node->next = ptr;
        prev->next = new_node;
    }

    return start;
}

void display(struct node *start)
{
    struct node *ptr = start;
    if (start == NULL)
        printf("\nQUEUE IS EMPTY");
    else
    {
        while (ptr != NULL)
        {
            printf("%s", ptr->str_data);
            ptr = ptr->next;
        }
    }
}