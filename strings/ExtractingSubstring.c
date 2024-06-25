#include <stdio.h>
#include <string.h>

int main(){
    char str[50], subs[50];
    int lenght = 0, index=0, i = 0;
    printf("Please enter the string:");
    gets(str);
    printf("Enter the position from which to start the substring: ");
    scanf("%d",&index);
    printf("Please enter the lenght of the substring: ");
    scanf("%d", &lenght);
    while (str[index] != '\0' && i < lenght)
    {
        subs[i] = str[index];
        index++;
        i++;
    }
    printf("The substring is : ");
    puts(subs);
    
}