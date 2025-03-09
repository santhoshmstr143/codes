#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int main()
{
    char s[MAX];
    scanf("%s", s);
    char stack[MAX + 1][MAX + 1];
    int top = -1;
    for (int i = 0; i < strlen(s); i++)
    {
        if (isOperator(s[i]))
        {
            char operand2[MAX + 1], operand1[MAX + 1];
            strcpy(operand2, stack[top--]);
            strcpy(operand1, stack[top--]);
            char result[MAX];
            sprintf(result, "(%s%c%s)", operand1, s[i], operand2);
            strcpy(stack[++top], result);
        }
        else
        {
            stack[++top][0] = s[i];
            stack[top][1] = '\0';
        }
    }
    printf("%s\n", stack[top]);
    return 0;
}
