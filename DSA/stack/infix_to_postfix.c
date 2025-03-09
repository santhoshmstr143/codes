#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int order(char op)
{
    switch (op)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

int oper(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int main()
{
    char *s = (char *)malloc(sizeof(char) * 100);
    scanf("%s", s);
    int n = strlen(s);
    char a[101];
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            printf("%c", s[i]);
        }
        else if (s[i] == '(')
        {
            a[++top] = s[i];
        }
        else if (s[i] == ')')
        {
            while (top != -1 && a[top] != '(')
            {
                printf("%c", a[top--]);
            }
            if (top != -1)
                top--;
        }
        else if (oper(s[i]))
        {
            while (top != -1 && (order(a[top]) > order(s[i]) || (order(a[top]) == order(s[i]) && s[i] != '^')))
            {
                printf("%c", a[top--]);
            }
            a[++top] = s[i];
        }
    }

    while (top != -1)
    {
        if (a[top] != '(')
            printf("%c", a[top]);
        top--;
    }

    free(s);
    return 0;
}
