#include <stdio.h>
#include <string.h>
int main(){
    char str[50], temp;
    int index = 0, length = 0;    
    printf("Please enter the string:");
    gets(str);
    length = strlen(str);
    while (index < length-1)
    {
        temp = str[index];
        str[index] = str[length-1];
        str[length-1] = temp;
        index++;
        length--;
    }
    puts(str);
    return 0;
}