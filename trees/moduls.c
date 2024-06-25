#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left;
    struct node *right;
    int data;
};
struct node *tree = NULL;
void create_tree(struct node *);
struct node *insertElement(struct node *, int);
struct node *deleteElement(struct node *, int);
struct node *findSmallestElement(struct node *);
struct node *findLargestElement(struct node *);
int totalNodes(struct node *);
int totalExternalNodes(struct node *);
int totalInternalNodes(struct node *);
int height(struct node *);
struct node *deleteTree(struct node *);
void display(struct node *);
int main()
{
    int option, value;
    struct node *ptr;
    do
    {

        printf("\n\n*****MAIN MENU*****\n");
        printf("1.Insert Element\n");
        printf("2.Delete Element\n");
        printf("3.Find Smallest Elemenet\n");
        printf("4.Find Largest Element\n");
        printf("5.Display the tree\n");
        printf("6.Count the total number of nodes\n");
        printf("7.Count the total number of external nodes\n");
        printf("8.Count the total number of internal nodes\n");
        printf("9.Determine the height of the tree\n");
        printf("10.Delete the tree\n");
        printf("11.EXIT\n");
        printf("Please enter your option: ");
        scanf(" %d", &option);
        switch (option)
        {
        case 1:
            printf("Please enter the value of the new node:");
            scanf("%d", &value);
            tree = insertElement(tree, value);
            break;
        case 2:
            printf("Please enter the element to be deleted:");
            scanf("%d", &value);
            tree = deleteElement(tree, value);
            break;
        case 3:
            ptr = findSmallestElement(tree);
            printf("The smallest value is %d", ptr->data);
            break;
        case 4:
            ptr = findLargestElement(tree);
            printf("The largest value is %d", ptr->data);
            break;
        case 5:
            display(tree);
            break;
        case 6:
            printf("Total no of nodes = %d", totalNodes(tree));
            break;
        case 7:
            printf("Total no of external nodes = %d", totalExternalNodes(tree));
            break;
        case 8:
            printf("Total no of internal nodes = %d", totalInternalNodes(tree));
            break;
        case 9:
            printf("The height of tree = %d", height(tree));
            break;
        case 10:
            tree = deleteTree(tree);
            break;
        default:
            break;
        }
    } while (option != 11);
    return 0;
}
void create_tree(struct node *tree)
{
    tree->left = NULL;
    tree->right = NULL;
}
struct node *insertElement(struct node *tree, int value)
{
    struct node *new_node, *parentptr, *nodeptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
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
            if (value < parentptr->data)
            { // ekleyeceğim değer parent'dan küçükse sola gitmem lazım
                nodeptr = parentptr->left;
            }
            else // ekleyeceğim değer parent'dan büyükse sağa gitmem lazım
            {
                nodeptr = parentptr->right;
            }
        }
        // döngüden çıktıktan sonra parentptr nin sağı solu boş ve nodeptr null gösteriyor olacak değerlerini atamam lazım. en son ulaştığım yaprak düğümden büyük mü küçük mü kontrolünü yapacağım
        if (value < parentptr->data)
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
struct node *deleteElement(struct node *tree, int value)
{
    struct node *current, *parent, *temp;
    if (tree == NULL)
    {
        printf("Value not found in the tree.\n");
    }
    else if (value > tree->data)
    {
        deleteElement(tree->right, value);
    }
    else if (value < tree->data)
    {
        deleteElement(tree->left, value);
    }
    else if ((tree->left != NULL) && (tree->right != NULL)) // sileceğim elemanın iki tane elemanı varsa ne yapacağım?
    {
        temp = findLargestElement(tree->left); // en soldakilen en büyüğünü bulabilirim. iki çocuğu olan düğüm yerine soldakilerin en büyüğünü yazmamda bir sorun olmaz
        tree->data = temp->data;
        deleteElement(tree->left, temp->data); // tree'nin üzerine değeri yazdığım için iki tane aynı değerden var. şimdi onu silmeye gidiyorum.
    }
    else
    {
        temp = tree;
        if (tree->left == NULL)
        {
            tree = tree->right;
        }
        else
        {
            tree = tree->left;
        }
        free(temp);
    }
    return tree;
}
struct node *findSmallestElement(struct node *tree)
{
    if (tree == NULL || tree->left == NULL)
    {
        return tree;
    }
    else
    {
        // recursive şeklilde solu çağırıp duracağım. en sola geldiğindeyse bir solu null olacağından en soldaki ifadeyi döndürür.
        return findSmallestElement(tree->left);
    }
}
struct node *findLargestElement(struct node *tree)
{
    if (tree == NULL || tree->right == NULL)
    {
        return tree;
    }
    else
    {
        // recursive şeklilde sağı çağırıp duracağım. en sağa geldiğindeyse bir sağı null olacağından en sağdaki ifadeyi döndürür.
        return findLargestElement(tree->right);
    }
}
int totalNodes(struct node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        return (totalNodes(tree->left) + totalNodes(tree->right) + 1);
    }
}
int totalExternalNodes(struct node *tree)
{
    // dıştaki düğümler yani yapraklar
    if (tree == NULL)
    {
        return 0;
    }
    else if ((tree->left == NULL) && (tree->right == NULL))
    {
        return 1;
    }
    else
    {
        return (totalExternalNodes(tree->left) + totalExternalNodes(tree->right));
    }
}
int totalInternalNodes(struct node *tree)
// içteki düğümler
{
    if (tree == NULL)
    {
        return 0;
    }
    else if ((tree->left != NULL) && (tree->right != NULL))
    {
        return 1;
    }
    else
    {
        return (totalInternalNodes(tree->right) + totalInternalNodes(tree->left) + 1);
    }
}
int height(struct node *tree)
{
    // en uzun yoldaki düğüm sayısı demektir.
    int leftHeight, rightHeight; // en uzun yol hangi tarafta bilmiyorum o yüzden iki tarafa da bakacağım.
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        leftHeight = height(tree->left);
        rightHeight = height(tree->right);
        if (leftHeight > rightHeight)
        {
            return (leftHeight + 1); //+1 diyorum çünkü root ile de toplamam lazım
        }
        else
        {
            return (rightHeight + 1);
        }
    }
}
struct node *deleteTree(struct node *tree)
{
    if (tree != NULL)
    {
        deleteTree(tree->right);
        deleteTree(tree->left);
        free(tree);
    }
}
void display(struct node *tree)
{
    // tree birden fazla şekilde basılabilir. preorder,inorder,postorder gibi. Biz burada inorder formatında bastıracağız.
    if (tree != NULL)
    {
        display(tree->left);
        printf("%d  ", tree->data);
        display(tree->right);
    }
}