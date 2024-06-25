#include <stdio.h>

typedef struct{
    int real;
    int image;
}Complex;

int main(){
    Complex c1,c2;
    int operation;

    while (operation != 5)
    {
        printf("\n******MAIN MENU******");
        printf("\n 1.Display");
        printf("\n 2.Read");
        printf("\n 3.Add");
        printf("\n 4.Subtract");
        printf("\n 5.EXIT");
    printf("\nPlease enter your option: ");
    scanf("%d", &operation);

        switch (operation)
        {
        case 1:
            printf("Please enter the real and imaginary parts of first complex number: ");
            scanf("%d %d",&c1.real,&c1.image);
            printf("Please enter the real and imaginary parts of second complex number: ");
            scanf("%d %d",&c2.real,&c2.image);
            break;
        case 2:
            printf("The first complex is: %d + %di\n",c1.real,c1.image);
            printf("The second complex is: %d + %di",c2.real,c2.image);
            break;
        case 3:
            Complex sum_c;
            sum_c.real = c1.real + c2.real;
            sum_c.image = c2.image + c2.image;
            printf("Sum of complex numbers is: %d + %di", sum_c.real, sum_c.image);
            break;
        case 4:
            Complex sub_c;
            sub_c.real = c1.real - c2.real;
            sub_c.image = c2.image - c2.image;
            printf("Subtract of complex numbers is: %d + %di", sub_c.real, sub_c.image);       
            break;
        default:
            break;
        }
    }
}