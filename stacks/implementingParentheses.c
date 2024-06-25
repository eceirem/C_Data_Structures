#include <stdio.h>
#include <string.h>
int stack[10], top = -1;

void push(char);
char pop();

int main()
{
    char exp[10], temp;
    int i, flag = 1;
    printf("Enter an expression: ");
    gets(exp);
    for (i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(exp[i]);
        }
        if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (top == -1)
            {
                flag = 0;
            }
            else
            {
                temp = pop();
                if (exp[i] == ')' && (temp == '[' || temp == '{')) // parantezler birbirlerini kesemezler öncesinde açılmış farklı tipte bir parantez varsa hata vardır.
                {
                    flag = 0;
                }
                if (exp[i] == '}' && (temp == '[' || temp == '(')) // parantezler birbirlerini kesemezler öncesinde açılmış farklı tipte bir parantez varsa hata vardır.
                {
                    flag = 0;
                }
                if (exp[i] == ']' && (temp == '(' || temp == '{')) // parantezler birbirlerini kesemezler öncesinde açılmış farklı tipte bir parantez varsa hata vardır.
                {
                    flag = 0;
                }
            }
        }
    }
    if (top >= 0) // bütün parantezler eşleşemedi ve kapanmayan parantez varsa, parantezler yanlış yerleştirilmiştir.
    {
        flag = 0;
    }
    if (flag)
    {
        printf("Valid expression.\n");
    }
    else
    {
        printf("Invalid expression.\n");
    }
    return 0;
}

void push(char ch)
{
    if (top == 9)
    {
        printf("Stack Overflow.\n");
    }
    else
    {
        stack[++top] = ch;
    }
}
char pop()
{
    char ch;
    if (top == -1)
    {
        printf("Stack Underflow.");
    }
    else
    {
        ch = stack[top];
        stack[top--];
        return ch;
    }
}