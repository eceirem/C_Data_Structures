#include <stdio.h>
typedef struct 
{
    char firstName[20];
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
}Student;

int main(){
    int n, num;
    int operation = 0;
    printf("Please enter the students number of class: ");
    scanf("%d",&n);
    Student std_array[n];
    for (int i = 0; i < n; i++)
    {
        printf("Please enter the student id: ");
        scanf("%d", &std_array[i].id);
        printf("\nPlease enter the full name: ");
        scanf("%s %s", std_array[i].name.firstName,std_array[i].name.surname);
        printf("Please enter the DOB: ");
        scanf("%d %d %d", &std_array[i].dob.dd,&std_array[i].dob.mm,&std_array[i].dob.yy);
    }
    printf("******INFORMATIONS ABOUT STUDENTS******\n");
    for (int i = 0; i < n; i++)
    {
        printf("Student Surname: %s\n", std_array[i].name.surname);
        printf("Student id: %d\n", std_array[i].id);
        printf("Student dob %d/%d/%d\n", std_array[i].dob.dd,std_array[i].dob.mm,std_array[i].dob.yy);
    }
    printf("Do you want to edit infos about students?(n:0/y:1)");
    scanf("%d", &operation);
    while (operation == 1)
    {
        printf("\n Enter the student id whose record has to be edited : ");
        scanf("%d", &num);
        for (int i = 0; i < n; i++)
        {
            if (num == std_array[i].id)
            {
            printf("\n Enter the new name : ");
            scanf("%s %s", std_array[i].name.firstName, std_array[i].name.surname);
            }
        }
        printf("Do you want to continue to edit infos about students?(n:0/y:1)");
        scanf("%d", &operation);
    }
    
    printf("******INFORMATIONS ABOUT STUDENTS******\n");
    for (int i = 0; i < n; i++)
    {
        printf("Student Surname: %s\n", std_array[i].name.surname);
        printf("Student id: %d\n", std_array[i].id);
        printf("Student dob %d/%d/%d\n", std_array[i].dob.dd,std_array[i].dob.mm,std_array[i].dob.yy);
    }


}