#include <stdio.h>

int main(){
    char str[50], pattern[20], replacing_pattern[20], newString[50];
    int index1 = 0, index2 = 0, index3 = 0, index4 = 0;
    printf("Enter the string: ");
    gets(str);
    printf("Enter the pattern to be replaced: ");
    gets(pattern);
    printf("Enter the replacing pattern: ");
    gets(replacing_pattern);
    while (str[index1] != '\0') //ilk str için bakıyorum.
    {
        if (str[index1] == pattern[index2]){ //çıkartmak istediğim pattern başladı
            while (pattern[index2] != '\0'){ 
                index1++;
                index2++;
            }
            if (pattern[index2] == '\0') //çıkartmak istediğim pattern bitti ve yerleştireceğimi eklemeye başlıyorum.
            {
                while (replacing_pattern[index3] != '\0') //yerleştirdim
                {
                    newString[index4] = replacing_pattern[index3];
                    index3++;
                    index4++;
                }
                
            }
            
        }
        else //çıkartmak istediğim pattern e gelene kadar ekleme yapıyorum.
        {
            newString[index4] = str[index1];
            index1++;
            index4++;
        }       
    }
    newString[index4] = '\0';
    printf("The new string is : %s", newString);
    return 0;    
}