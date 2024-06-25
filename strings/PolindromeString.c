#include <stdio.h>

int main(){
    char str[50];
    int index = 0, index_back = 0, lenght = 0;
    printf("Please enter the string:");
    gets(str);
    while (str[index] != '\0')
    {
        lenght++;
        index++;
    }
    index = 0;
    index_back = lenght - 1;
    while (index <= lenght/2)
    {
        if (str[index] == str[index_back])
        {
            index++;
            index_back--;
        }
        else{
            break;
        }        
    }
    if (index >= index_back)
    {
        printf("Polindrome\n");
    }
    else
    {
        printf("Not a Polindrome\n");
    }
    return 0;
    
}