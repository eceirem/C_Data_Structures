#include <stdio.h>

int main(){
    char str1[100], str2[100], copy_str[100];
    char *pstr1, *pstr2, *pcopy_str;
    pstr1 = str1;
    pstr2 = str2;
    pcopy_str = copy_str;
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);
    while (*pstr1 != '\0')
    {
        *pcopy_str = *pstr1;
        pstr1++;
        pcopy_str++;
    }
    while(*pstr2 != '\0')
    {
        *pcopy_str = *pstr2;
        pstr2++;
        pcopy_str++;
    }
    *pcopy_str = '\0';
    printf("\n The concatenated text is: %s", copy_str);
    return 0;
    
}