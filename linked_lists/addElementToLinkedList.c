#include <stdio.h>
#include <stdlib.h>

struct node
{
    int x;
    struct node *next;
};
typedef struct node Node;

void display(Node * r){
    int i = 0;
    while (r != NULL)
    {
        i++;
        printf("%d. eleman: %d\n",i, r -> x);
        r = r -> next;        
    }
}
void get(Node *r, int x){
    while (r -> next != NULL)
    {
        r = r -> next;
    }    
    r -> next = (Node *)malloc(sizeof(Node));
    r -> next -> x = x;
    r -> next -> next = NULL;
}
int main() {
    Node *root;
    root = (Node *)malloc(sizeof(Node));  
    root ->next = NULL;  
    root -> x = 500;
    for (int i = 0; i < 5; i++)
    {
        get(root, i*10);
    }
    display(root);
    Node * iter = root;
    for (int i = 0; i < 3; i++)
    {
        iter = iter -> next;
    }
    Node * temp = (Node*)malloc(sizeof(Node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> x = 100;
    display(root);
    
    return 0;
}

// struct node *ekleSirali(struct node*start, int x){
//     struct node *new_node, *ptr;
//     if (start == NULL)
//     {
//         start = (struct node *)malloc(sizeof(struct node));
//         start ->next = start;
//         start ->data = x;
//         return start;
//     }
//     if (start ->data > x)  //ilk elemandan küçük durumu
//     {
//         new_node = (struct node *)malloc(sizeof(struct node));
//         new_node->data = x;
//         new_node->next = start;
//         start = new_node;
//         ptr = start;
//         ptr = ptr -> next;
//         while (ptr->next != start)
//         {
//             ptr = ptr ->next;
//         }
//         ptr ->next = start;
//     }    
//     ptr = start;
//     ptr = ptr -> next;
//     while (ptr->next != start && ptr->next->data < x)
//     {
//         ptr = ptr -> next;
//     }
//     new_node = (struct node*)malloc(sizeof(struct node));
//     new_node -> data = x;
//     new_node ->next = ptr -> next;
//     ptr ->next = new_node;    
//     return start;
// }