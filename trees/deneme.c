#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left;
    struct node *right;
    int id;
    int note;
};
struct node *tree = NULL;
struct node *insertElement(struct node *, int, int);
void InOrderDisplay(struct node *);
void display(struct node *);

int main()
{
    int id, note;
    while (1)
    {
        scanf("%d", &id);

        if (id == -1)
        {
            break;
        }

        scanf("%d", &note);
        tree = insertElement(tree, id, note);
    }
    InOrderDisplay(tree);
    printf("\n");
    printf("%d %d\n", tree->id, tree->note);
    display(tree);
    return 0;
}

struct node *insertElement(struct node *tree, int id, int note)
{
    struct node *new_node, *parentptr, *nodeptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->id = id;
    new_node->note = note;
    new_node->left = NULL;
    new_node->right = NULL;
    if (tree == NULL) // tree'de herhangi bir değer yoksa ilk değerim ilk node'um olacak.
    {
        tree = new_node;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr; // while'dan çıkmadan önce şu anki node bir sonraki node un parent ı olacağından güncellenmeli
            if (note < parentptr->note)
            { // ekleyeceğim değer parent'dan küçükse sola gitmem lazım
                nodeptr = parentptr->left;
            }
            else // ekleyeceğim değer parent'dan büyükse sağa gitmem lazım
            {
                nodeptr = parentptr->right;
            }
        }
        // döngüden çıktıktan sonra parentptr nin sağı solu boş ve nodeptr null gösteriyor olacak değerlerini atamam lazım. en son ulaştığım yaprak düğümden büyük mü küçük mü kontrolünü yapacağım
        if (note < parentptr->note)
        {
            parentptr->left = new_node;
        }
        else
        {
            parentptr->right = new_node;
        }
    }
    return tree;
}
void InOrderDisplay(struct node *tree)
{
    // tree birden fazla şekilde basılabilir. preorder,inorder,postorder gibi. Biz burada inorder formatında bastıracağız.
    if (tree != NULL)
    {
        InOrderDisplay(tree->left);
        printf("%d %d\n", tree->id, tree->note);
        InOrderDisplay(tree->right);
    }
}
//height ile denemen lazım bir de
void display(struct node *tree)
{
    if (tree != NULL)
    {
        if (tree->left != NULL)
        {
            printf("%d %d (%d L) ", tree->left->id, tree->left->note, tree->note);
        }

        if (tree->right != NULL)
        {
            printf("%d %d (%d R) ", tree->right->id, tree->right->note, tree->note);
            printf("\n");
        }
        display(tree->left);
        display(tree->right);
    }
}
