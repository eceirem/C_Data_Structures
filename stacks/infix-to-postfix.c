#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100

char stack[MAX];

char infix[MAX], postfix[MAX];

int top = -1;

void push(char);
char pop();
int isEmpty();
void inToPost();
int space(char);
void print();
int precedence(char);
float evaluatePostfixExp(char exp[]);

int main()
{
    float val;
    printf("Enter the infix expression: ");
    gets(infix);
    inToPost();
    print();
    val = evaluatePostfixExp(postfix);
    return 0;
}
void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow.");
    }
    else
    {
        stack[++top] = ch;
    }
}
char pop()
{
    char c;
    if (top == -1)
    {
        printf("Stack Underflow.");
    }
    else
    {
        c = stack[top];
        top = top - 1;
        return c;
    }
}
int isEmpty()
{
    return (top == -1);
}
int space(char s)
{
    return (s == ' ' || s == '\t');
}
int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
void inToPost()
{
    int i, j = 0;
    char symbol, next;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if (!space(symbol))
        {
            switch (symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while ((next = pop()) != '(') // pop ettikten sonra kontrol ediyorum yani sağdaki parantezi de çıkarmış olacağım.
                {
                    postfix[j++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                {
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default: // operant geldiğinde default olarak postfix e eklemem lazım.
                postfix[j++] = symbol;
                break;
            }
        }
    }
    while (!isEmpty())
    {
        postfix[j++] = pop(); // stack teki kalanların hepsini ekliyorum çünkü yapacağım işlemler bitti. Tüm ifadede gezidm ve bazı operantları stack'e attım. Öncelikli olanlar postfix'de ama diğerleri stack'de kaldığı için almam lazım!!!
    }
    postfix[j] = '\0';
}
void print()
{
    int i;
    for (i = 0; i < strlen(postfix); i++)
    {
        printf("%c", postfix[i]);
    }
}
