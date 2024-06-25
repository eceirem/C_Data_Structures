#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char firstName[20];
    char surname[20];
} Name;

typedef struct 
{
    int id;
    Name name;
} Student;

void display(Student *ptr){
    printf("\n DETAILS OF STUDENT");
    printf("\n ID: = %d", ptr->id);
    printf("\n NAME = %s %s", ptr->name.firstName, ptr->name.surname);
}

int main(){
    Student *ptr;
    ptr = (Student *)malloc(sizeof(Student));

    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("\nEnter the student id: ");
    scanf("%d", &ptr->id);
    printf("\nEnter the name: ");
    scanf("%s %s", ptr->name.firstName, ptr->name.surname);
    display(ptr);

    // Belleği geri ver
    free(ptr);

    return 0;
}
