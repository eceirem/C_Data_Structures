#include <stdio.h>
#include <string.h>
void sortNames(char names[][10], int num) {
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                char temp[10];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

int main() {
    int num;
    printf("Enter the number of students: ");
    scanf("%d", &num);

    char names[num][10];

    for (int i = 0; i < num; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", names[i]);
    }


    // İsimleri sırala
    sortNames(names, num);

    // Sıralanmış isimleri yazdır
    printf("Sorted names:\n");
    for (int i = 0; i < num; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
