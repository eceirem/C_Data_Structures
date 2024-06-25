#include <stdio.h>
#include <stdlib.h>
 typedef struct 
 {
    int id;
    char firstName[20];
    char course[20];
 }Student;
 
 int main(){
    Student std1;
    printf("\nEnter the id: ");
    scanf("%d", &std1.id);
    printf("\nEnter the first name: ");
    scanf("%s", std1.firstName);
    printf("\nEnter the course name: ");
    scanf("%s", std1.course);
    printf("*****STUDENT INFORMATIONS*****\n");
    printf("Name: %s\n", std1.firstName);
    printf("ID: %d\n",std1.id );
    printf("Course: %s\n", std1.course);
 }

