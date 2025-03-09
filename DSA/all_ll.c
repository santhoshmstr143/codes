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

int size(node *l)
{
    int s = 0;
    while (l != NULL)
    {
        l = l->next;
        s++;
    }
    return s;
}

void createnode(node *head, int data)
{
    node *k = (node *)malloc(sizeof(node));
    k->data = data;
    k->next = NULL;
    node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = k;
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

node *append(int val, node *head)
{
    node *k, *ptr = head;
    k = (node *)malloc(sizeof(node));
    k->data = val;
    k->next = NULL;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = k;
    return head;
}

node *reverse(node *head)
{
    node *c = head, *n = NULL, *p = NULL;
    while (c != NULL)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    return p;
}

node *shuffle(node *a, node *b)
{
    node *x, *y, *k = a;
    while (a != NULL && b != NULL)
    {
        x = a->next;
        y = b->next;
        a->next = b;
        if (a == NULL)
        {
            break;
        }
        b->next = x;
        a = x;
        b = y;
    }
    return k;
}

node* copy(node *head) {
    if (head == NULL) {
        return NULL;
    }
    node *newHead = (node *)malloc(sizeof(node));
    newHead->data = head->data;
    newHead->next = NULL;
    node *newCurrent = newHead;
    node *originalCurrent = head->next;
    while (originalCurrent != NULL) {
        node *newNode = (node *)malloc(sizeof(node));
        newNode->data = originalCurrent->data;
        newNode->next = NULL;
        newCurrent->next = newNode;
        newCurrent = newNode;
        originalCurrent = originalCurrent->next;
    }
    return newHead;
}

int main()
{
    int n, m;
    printf("enter the no of ll\n");
    scanf("%d", &n);
    node *head = (node *)malloc(sizeof(node));
    head->next = NULL;
    printf("enter size value of ll\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        createnode(head, m);
    }
    head = head->next;
    int z;
    printf("0-show ll\n1-size\n2-sort ll\n3-insert at pos\n4-append at end\n5-reverse\n6-shuffle\n7-copy_ll\n");
    printf("enter a number to perform the recpective op: ");
    scanf("%d", &z);
    if (z == 0)
    {
        printf("here is the ll\n");
        print(head);
    }
    else if (z == 1)
    {
        // size of ll
        printf("size of ll: %d\n", size(head));
    }
    else if (z == 2)
    {
        // to sort linked list
        printf("sorted ll:\n");
        head = sort(head);
        print(head);
    }
    else if (z == 3)
    {
        // to insert at pos p
        printf("to insert at some position enter pos,val\n");
        int pos, val;
        scanf("%d %d", &pos, &val);
        head = insert(pos, val, head);
        print(head);
    }
    else if (z == 4)
    {
        // append at end
        printf("enter the vaue to be appended\n");
        int appen;
        scanf("%d", &appen);
        head = append(appen, head);
        print(head);
    }
    else if (z == 5)
    {
        // reverse ll
        printf("reverse ll\n");
        node *r = reverse(head);
        print(r);
    }
    else if (z == 6)
    {
        // // shuffle a-b-c, 1-2-3 = a-1-b-2-c-3
        int p, q;
        printf("enter the no of 2nd ll\n");
        scanf("%d", &p);
        node *head1 = (node *)malloc(sizeof(node));
        head1->next = NULL;
        printf("enter each value of ll\n");
        for (int i = 0; i < p; i++)
        {
            scanf("%d", &q);
            createnode(head1, q);
        }
        head1 = head1->next;
        printf("here is the 2nd ll\n");
        print(head1);
        node *k;
        printf("shuffle ll\n");
        k = shuffle(head, head1);
        print(k);
    }
    else if(z==7)
    {
        //copy ll
        node *k;
        k = copy(head);
        print(k);
    }
}