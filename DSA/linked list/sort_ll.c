#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

void print(node *head)
{
    node *a = head;
    while (a != NULL)
    {
        printf("%d ", a->data);
        a = a->next;
    }
    printf("\n");
}

node *createnode(int data)
{
    node *a = (node *)malloc(sizeof(node));
    a->data = data;
    a->next = NULL;
    return a;
}

node *sort(node *head)
{
    node *pre = NULL, *dup = NULL, *ptr, *ptr1;
    ptr = head;
    while (ptr != NULL)
    {
        ptr1 = head;
        pre = NULL;
        while (ptr1 != NULL && ptr1->next != NULL)
        {
            if (ptr1->next->data < ptr1->data)
            {
                dup = ptr1->next;
                ptr1->next = dup->next;
                dup->next = ptr1;
                if (pre == NULL)
                {
                    head = dup;
                }
                else
                {
                    pre->next = dup;
                }
            }
            pre = ptr1;
            ptr1 = ptr1->next;
        }
        ptr = ptr->next;
    }
    return head;
}

int main()
{
    node *head, *ptr;
    head = NULL;
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        node *newNode = createnode(k);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            ptr->next = newNode;
        }
        ptr = newNode;
    }
    print(head);
    printf("sorted\n");
    head=sort(head);
    print(head);
    return 0;
}