#include <stdio.h>

typedef struct 
{
    char firstName[20];
    char secondName[20];
    char surname[20];
}Name;

typedef struct
{
    int dd;
    int mm;
    int yy;
}Date;

typedef struct 
{
    int id;
    Name name;
    Date dob;
    char course[20];
}Student;

int main(){
    Student std1;
    Student std2;
    strcpy(std1.name.firstName, "Ece");
    strcpy(std1.name.secondName, "Irem");
    strcpy(std1.name.surname, "Siser");
    strcpy(std1.course, "BLM2067");
    std1.dob.dd = 29;
    std1.dob.mm = 12;
    std1.dob.yy = 2003;
    printf("Please enter the student id: ");
    scanf("%d", &std2.id);
    printf("\nPlease enter the full name: ");
    scanf("%s %s %s", std2.name.firstName, std2.name.secondName,std2.name.surname);
    printf("Please enter the DOB: ");
    scanf("%d %d %d", &std2.dob.dd,&std2.dob.mm,&std2.dob.yy);
    printf("\nPlease enter the course name: ");
    scanf("%s", std2.course);
    printf("******INFORMATIONS******\n");
    printf("Student Surname: %s\n", std2.name.surname);
    printf("Student id: %d\n", std2.id);
    printf("Student dob %d/%d/%d\n", std2.dob.dd,std2.dob.mm,std2.dob.yy);
    printf("Course Name: %s", std2.course);
}


