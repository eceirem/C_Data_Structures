#include <stdio.h>

int main() {
    char str[50], ch;
    int len = 0, index = 0, word_c = 1, line_c = 1, char_c = 1;

    printf("Enter '*' to end.\n");
    printf("Enter the text: ");
    
    while ((ch = getchar()) != '*') {
        str[len] = ch;
        len++;
    }
    str[len] = '\0';

    while (str[index] != '\0') {
        if (str[index] == '\n') {
            line_c++;
            word_c++;
        }
        if (str[index] == ' ' && str[index + 1] != ' ') {
            word_c++;
        }
        char_c++;
        index++;
    }

    printf("%d lines\n%d words\n%d char\nin this string.\n", line_c, word_c, char_c);
    return 0;
}
