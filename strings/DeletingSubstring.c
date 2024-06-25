#include <stdio.h>

int main(){
    char str[50], delete_str[50], new_str[50];
    int index1 = 0, index2 = 0, index3 = 0;
    printf("Enter the main text: ");
    gets(str);
    printf("Enter the string to be deleted: ");
    gets(delete_str);
    while (str[index1] != '\0')
    {
        if (str[index1]==delete_str[index2])
        {
            index1++;
            index2++;
        }
        else
        {
            new_str[index3] = str[index1];
            index1++;
            index3++;
        }       
    }
    new_str[index3] = '\0';
    printf("The new string is: %s", new_str);

}