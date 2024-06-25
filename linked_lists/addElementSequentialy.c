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
Node *addSequentialy(Node * r, int x){
    //linklist boşsa
    if (r == NULL)
    {
        r = (Node *)malloc(sizeof(Node));
        r ->next = NULL;
        r ->x = x;
        return r;
    }
    //linkliste root tan küçük bir değer geldi başa eklemem lazım.
    //root değeri değişiyor.
    if (r->x > x)
    {
        Node * temp = (Node *)malloc(sizeof(Node));
        temp -> x = x;
        temp -> next = r;
        r = temp;
        return r;
    }
    Node * iter = r;
    while (iter->next != NULL && iter->next->x < x)
    {
        iter = iter -> next;
    }
    Node * temp = (Node *)malloc(sizeof(Node));
    temp ->next = iter -> next;
    iter ->next = temp;
    temp -> x = x;
    return r;  
    
}
int main() {
    Node *root;
    root = NULL;
    root = addSequentialy(root,400);
    root = addSequentialy(root,40);
    root = addSequentialy(root,4);
    root = addSequentialy(root,450);
    root = addSequentialy(root,50);
    display(root);
    return 0;
}