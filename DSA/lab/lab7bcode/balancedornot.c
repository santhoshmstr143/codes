#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
node *create()
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
int height (node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    int h = (lh > rh)? lh : rh;
    return h + 1;
}
int main()
{
    int n;
    scanf("%d", &n);
    int parent[n + 1];
    node *nodes[n + 1];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &parent[i]);
        nodes[i] = create();
    }
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == -1)
        {
            root = nodes[i];
        }
        else
        {
            node *parentnode = nodes[parent[i]];
            if (parentnode->left == NULL)
            {
                parentnode->left = nodes[i];
            }
            else
            {
                parentnode->right = nodes[i];
            }
        }
    }
    int balanced = 1;
    for(int i=0;i<n;i++)
    {
        int lh = height(nodes[i]->left);
        int rh = height(nodes[i]->right);
        int d = (lh > rh)? lh - rh : rh - lh;
        if(d > 1)
        {
            balanced = 0;
            break;
        }
    }
    if(balanced == 1)
    {
        printf("Balanced\n");
    }
    else if(balanced == 0)
    {
        printf("Not balanced\n");
    }

    
}