#include <stdio.h>

int main(){
    char str1[50], str2[50], new_str[100];
    int position, index1 = 0, index2 = 0, index3 = 0;
    printf("Enter the main string please: ");
    scanf("%s", str1);
    printf("Enter the string to be inserted please: ");
    scanf("%s", str2);
    printf("Enter the position at which the string has to be inserted:");
    scanf("%d", &position);

    while (str1[index1] != '\0')
    {
        if (index1 == position)
        {
            while (str2[index2] != '\0')
            {
                new_str[index3] = str2[index2];
                index3++;
                index2++;
            }          
        }
        else
        {
            new_str[index3] = str1[index1];
            index3++;    
            index1++;        
        }
        
    }
    new_str[index3] = '\0';
    printf("The new string is: %s", new_str);
    return 0;
}