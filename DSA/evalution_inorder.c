#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int numStack[MAX], top = -1;
char opStack[MAX];
int opTop = -1;

int order(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int applyOperation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
    {
        int res = 1;
        for (int i = 0; i < b; i++)
            res *= a;
        return res;
    }
    }
    return 0;
}

void processOperator()
{
    int b = numStack[top--];
    int a = numStack[top--];
    char op = opStack[opTop--];
    numStack[++top] = applyOperation(a, b, op);
}

int evaluateInfix(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isdigit(s[i]))
        {
            int num = 0;
            while (isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;
            numStack[++top] = num;
        }
        else if (s[i] == '(')
        {
            opStack[++opTop] = s[i];
        }
        else if (s[i] == ')')
        {
            while (opTop != -1 && opStack[opTop] != '(')
            {
                processOperator();
            }
            opTop--;
        }
        else if (order(s[i]))
        {
            while (opTop != -1 && order(opStack[opTop]) >= order(s[i]) && s[i]!='^')
            {
                processOperator();
            }
            opStack[++opTop] = s[i];
        }
    }
    while (opTop != -1)
    {
        processOperator();
    }
    return numStack[top];
}

int main()
{
    char s[MAX];
    scanf("%s", s);
    printf("%d\n", evaluateInfix(s));
    return 0;
}