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
    root -> x = 0;
    for (int i = 0; i < 5; i++)
    {
        get(root, i*10);
    }
    display(root);
    return 0;
}
