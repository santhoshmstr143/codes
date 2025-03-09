#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int main()
{
    int n;
    scanf("%d", &n);
    int parent[n + 1];
    node *nodes[n + 1];

    for (int i = 1; i <= n; i++)
    {
        nodes[i] = create(i);
        int x;
        scanf("%d", &x);
        nodes[i]->data = x;
    }

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &parent[i]);
    }

    node *root = NULL;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == -1)
            root = nodes[i];
        else
        {
            node *parentnode = nodes[parent[i]];
            if (parentnode->left == NULL)
                parentnode->left = nodes[i];
            else
                parentnode->right = nodes[i];
        }
    }
    
    int count = 0;
    int visited[n + 1];
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (nodes[i]->left == NULL && nodes[i]->right == NULL)
        {
            if (nodes[i]->data == 1 && !visited[i])
            {
                count++;
                int a = i;
                while (a != -1 && !visited[a])
                {
                    visited[a] = 1;
                    a = parent[a];
                }
            }
            else
            {
                int a = i;
                while (parent[a] != -1)
                {
                    int par = parent[a];
                    if (nodes[par]->data == 1 && !visited[par])
                    {
                        count++;
                        int b = par;
                        while (b != -1 && !visited[b])
                        {
                            visited[b] = 1;
                            b = parent[b];
                        }
                        break;
                    }
                    a = par;
                }
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
