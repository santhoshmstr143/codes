#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int a[MAX];
int top = -1;

void push(int val)
{
    if (top == MAX - 1)
    {
        printf("Stack is full.\n");
    }
    else
    {
        a[++top] = val;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    else
    {
        return a[top--];
    }
}

void reverse()
{
    if (top != -1)
    {
        int temp = pop();
        reverse();
        push(temp);
    }
}

int main()
{
    int m;
    scanf("%d", &m);
    printf("%d", m);
    for (int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);
        push(x);
    }
    reverse();
    while (top != -1)
    {
        printf("%d ", pop());
    }
    printf("\n");
    return 0;
}
