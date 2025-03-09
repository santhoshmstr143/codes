#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct
{
    int arr[MAX];
    int front, rear, size;
} Queue;

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void enqueue(Queue *q, int x)
{
    if (q->size == MAX)
    {
        printf("Queue overflow\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = x;
    q->size++;
}

int dequeue(Queue *q)
{
    if (q->size == 0)
    {
        printf("Queue underflow\n");
        return -1;
    }
    int temp = q->arr[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return temp;
}

int front(Queue *q)
{
    if (q->size == 0)
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

int size(Queue *q)
{
    return q->size;
}

typedef struct
{
    Queue *q;
} MyStack;

MyStack *myStackCreate()
{
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->q = (Queue *)malloc(sizeof(Queue));
    initQueue(s->q);
    return s;
}

void myStackPush(MyStack *s, int x)
{
    int sz = size(s->q);
    enqueue(s->q, x);
    for (int i = 0; i < sz; i++)
    {
        enqueue(s->q, dequeue(s->q));
    }
}

int myStackPop(MyStack *s)
{
    return dequeue(s->q);
}

int myStackTop(MyStack *s)
{
    return front(s->q);
}

bool myStackEmpty(MyStack *s)
{

    return size(s->q) == 0;
}

void myStackFree(MyStack *s)
{
    free(s->q);
    free(s);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
 * hi
*/