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
node *insert(int pos, int val, node *head)
{
    node *k, *ptr = head;
    k = (node *)malloc(sizeof(node));
    k->data = val;
    k->next = NULL;
    if (pos == 0)
    {
        k->next = head;
        return k;
    }
    else
    {
        while (ptr->next != NULL)
        {
            pos--;
            if (pos == 0)
            {
                k->next = ptr->next;
                ptr->next = k;
                break;
            }
            ptr = ptr->next;
        }
        if (pos != 0)
        {
            ptr->next = k;
        }
        return head;
    }
}

int main()
{
    node *head, *ptr;
    head = NULL;
    int n, p,k,val;
    scanf("%d ", &n);
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
    
    printf("enter pos and val\n");
    scanf("%d %d",&p,&val);
    head=insert(p,val,head);
    print(head);
    return 0;
}