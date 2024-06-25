#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100

float stack[MAX];
char postfix[MAX];
int top = -1;

void push(float);
float pop();
float evaluatePostfixExp(char exp[]);
int main()
{
    float value;
    printf("Please enter any postfix expression: ");
    gets(postfix);
    value = evaluatePostfixExp(postfix);
    printf("Value of the postfix expression = %.2f", value);
    return 0;
}

float evaluatePostfixExp(char exp[])
{
    int i = 0;
    float op1, op2, val;
    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]))
        {
            push((postfix[i] - '0'));
        }
        else
        {
            op2 = pop();
            op1 = pop();
            switch (postfix[i])
            {
            case '+':
                val = op1 + op2;
                break;
            case '-':
                val = op1 - op2;
                break;
            case '/':
                val = op1 / op2;
                break;
            case '*':
                val = op1 * op2;
                break;
            case '^':
                val = pow(op1, op2);
                break;
            case '%':
                val = (int)op1 % (int)op2;
                break;
            }
            push(val);
        }
        i++;
    }
    return pop();
}

void push(float val)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow.");
    }
    else
    {
        stack[++top] = val;
    }
}

float pop()
{
    if (top == -1)
    {
        printf("Stack Underflow.");
    }
    else
    {
        return stack[top--];
    }
}