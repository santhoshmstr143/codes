#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
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

int main()
{
    char s[MAX];
    scanf("%s", s);
    int a[MAX];
    int top = -1;
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]))
        {
            a[++top]=s[i]-'0';
        }
        else if(isOperator(s[i]))
        {
            int op2 = a[top--];
            int op1 = a[top--];
            a[++top] = applyOperation(op1, op2, s[i]);
        }
    }
    printf("%d\n", a[top]);
    return 0;
}
