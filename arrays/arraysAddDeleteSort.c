#include <stdio.h>
void bubbleSort(int a[], int size);
int linearSearch(int a[], int size, int x);
int binarySearch(int a[], int size, int x);
void deleteItem(int a[], int *size, int delete);
void addItem(int a[], int *size, int x);
void printArray(int c[], int size);
int main()
{
    int index = 0;
    int index2 = 0;
    int key = 81;
    int arr[10] = {79, 34, 64, 81, 23, 12, 56, 87, 21, 90};
    int size = 10;
    int deleteNum = 0;
    int delItem = 0;
    int addNum = 0;
    int additem = 0;
    printf("The array is:\n");
    printArray(arr, size);
    printf("After Bubble Sort:\n");
    bubbleSort(arr, size);
    printArray(arr, size);
    printf("Find 81 with Linear Search: \n");
    index = linearSearch(arr, size, key);
    printf("The %d is on the %dth index. \n", key, index);
    printf("Find 81 with Binary Search: \n");
    index2 = binarySearch(arr, size, key);
    printf("The %d is on the %dth index. \n", key, index2);
    printf("Please enter item count which you want to delete.\n");
    scanf("%d ", &deleteNum);
    for (int i = 0; i < deleteNum; i++)
    {
        scanf("%d", &delItem);
        deleteItem(arr, &size, delItem);
    }
    printf("Let's look after deleting element in array:\n");
    printArray(arr, size);
    printf("Please enter item count which you want to add.\n");
    scanf("%d", &addNum);
    for (int i = 0; i < addNum; i++)
    {
        scanf("%d", &additem);
        addItem(arr, &size, additem);
    }
    printf("Let's look after adding element in array:\n");
    printArray(arr, size);
    printf("After Bubble Sort:\n");
    bubbleSort(arr, size);
    printArray(arr, size);
}

void bubbleSort(int a[], int size)
{
    int hold = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (a[j + 1] < a[j])
            {
                hold = a[j];
                a[j] = a[j + 1];
                a[j + 1] = hold;
            }
        }
    }
}

int linearSearch(int a[], int size, int x)
{
    for (int i = 0; i < size; i++)
    {
        if (x == a[i])
        {
            return i;
        }
    }
}
int binarySearch(int a[], int size, int x)
{
    int low = 0;
    int high = size - 1;
    int middle = 0;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (a[middle] == x)
        {
            return middle;
        }
        else if (a[middle] < x)
        {
            low = middle + 1;
        }
        else
        {
            high = middle - 1;
        }
    }
    return -1;
}

void deleteItem(int a[], int *size, int delete)
{
    int delSize = 0;
    int founded = binarySearch(a, *size, delete);
    if (founded == -1)
    {
        printf("We can not delete that item because it is not exist.\n");
    }
    else
    {
        for (int i = founded; i < *size; i++)
        {
            a[i] = a[i + 1];
        }
        delSize++;
    }

    *size -= delSize;
}

void addItem(int a[], int *size, int x)
{
    a[*size] = x;
    (*size)++;
}

void printArray(int c[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", c[i]);
    }
    puts("");
}

// GPT
//  #include <stdio.h>

//  #define MAX_SIZE 100 // Dizinin maksimum boyutu
//  void addItem(int a[], int *size, int x) {
//      if (*size < MAX_SIZE) {
//          a[*size] = x;
//          (*size)++;
//      } else {
//          printf("Dizi maksimum boyuta ulaştı, öğe eklenemedi.\n");
//      }
//  }
//  int main() {
//      int arr[MAX_SIZE]; // Boş bir dizi oluşturuldu
//      int size = 0; // Dizinin başlangıç boyutu
//      printf("Boş dizi oluşturuldu.\n");
//      printf("Let's add the element: %d\n", 56);
//      addItem(arr, &size, 56);
//      printf("Let's look after adding element in array:\n");
  
//      for (int i = 0; i < size; i++) {
//          printf("%d ", arr[i]);
//      }
//      printf("\n");
//      return 0;
//  }
