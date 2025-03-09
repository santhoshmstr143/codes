#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct
{
    int a[MAX];
    int size;
    int top;
} stack;

void initstack(stack *s)
{
    s->size = 0;
    s->top = -1;
}

void push(stack *s, int x)
{
    if (s->top == MAX - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        s->a[++s->top] = x;
        s->size++;
    }
}

int pop(stack *s)
{
    if (s->size == 0)
    {
        return -1;
    }
    s->size--;
    return s->a[s->top--];
}

int peek(stack *s)
{
    if (s->size == 0)
    {
        return -1;
    }
    return s->a[s->top];
}

bool isEmpty(stack *s)
{
    return s->size == 0;
}

typedef struct
{
    stack *s1;
    stack *s2;
} MyQueue;

MyQueue *myQueueCreate()
{
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->s1 = (stack *)malloc(sizeof(stack));
    q->s2 = (stack *)malloc(sizeof(stack));
    initstack(q->s1);
    initstack(q->s2);
    return q;
}

void myQueuePush(MyQueue *q, int x)
{
    push(q->s1, x);
}

int myQueuePop(MyQueue *q)
{
    if (isEmpty(q->s2))
    {
        while (!isEmpty(q->s1))
        {
            push(q->s2, pop(q->s1));
        }
    }
    return pop(q->s2);
}

int myQueuePeek(MyQueue *q)
{
    if (isEmpty(q->s2))
    {
        while (!isEmpty(q->s1))
        {
            push(q->s2, pop(q->s1));
        }
    }
    return peek(q->s2);
}

bool myQueueEmpty(MyQueue *q)
{
    return isEmpty(q->s1) && isEmpty(q->s2);
}

void myQueueFree(MyQueue *q)
{
    free(q->s1);
    free(q->s2);
    free(q);
}
