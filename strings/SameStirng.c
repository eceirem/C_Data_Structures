#include <stdio.h>
#include <string.h>

int main(){
    char str1[50], str2[50];
    int len1 = 0, len2 = 0, i = 0;
    printf("Please enter the first string: ");
    gets(str1);
    printf("Please enter the second string: ");
    gets(str2);   
    len1 = strlen(str1);
    len2 = strlen(str2);    
    if (len1 == len2)
    {
        while (i < len1)
        {
            if (str1[i]!=str2[i])
            {
                printf("Strings are not equal!");
                return 0;
            }  
            i++;          
        }
        printf("Strings are equal.");
          
    }
    else
    {
        printf("Strings are not equal!\n");
        if (len1 < len2)
        {
            printf("String2 is greater than String1.");
        }
        else{
            printf("String1 is greater than String2.");
        }
        
    }

    
    
    return 0;
}