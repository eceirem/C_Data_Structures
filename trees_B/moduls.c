#include <stdio.h>
#include <stdlib.h>
#define HEIGHT 3
struct Tree
{
    int *keys;                // şu anki değerlerimin tutulduğu array
    struct Tree *(*children); // çocukları array tipinde olacağından pointer ile arrayi gösteriyorum.
    struct Tree *(*parent);
    int val;
    int height;
    char type;
};
struct Tree *tree = NULL;
struct Tree *insert(struct Tree *);
struct Tree *split(struct Tree *);
void printCurrentLevel(struct Tree *tree, int level);

// aynı seviyedeki Tree'ları bastırmak için bir döngü içerisinde çağırıyorum
void printLevelOrder(struct Tree *tree)
{
    int h = HEIGHT;
    int i;
    for (i = 1; i <= h; i++)
    {
        printCurrentLevel(tree, i);
        printf("\n");
    }
}

// aynı seviyedeki Tree'ları basar
void printCurrentLevel(struct Tree *tree, int level)
{
    if (tree == NULL)
        return;
    if (level == 1)
    {
        if (tree->type == 'T')
        {
            printf("%d ", tree->val);
        }
        else
        {
            printf("%d (%d %c)", tree->val, tree->parent, tree->type);
        }
    }
    else if (level > 1)
    {
        printCurrentLevel(tree->children, level - 1);
    }
}