#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct node
{
    int a;
    int d;
    int count;
    struct node *left;
    struct node *right;
    int sum;
} node;

node *create(int a, int b)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->a = a;
    temp->d = b;
    temp->count = 1;
    temp->left = NULL;
    temp->right = NULL;
    temp->sum = a + b;
    return temp;
}

node *insert(node *root, int a, int d)
{
    if (root == NULL)
    {
        return create(a, d);
    }

    if (a + d == root->sum)
    {
        if (a == root->a && d == root->d)
        {
            root->count++;
        }
        else if (a > root->a)
        {
            root->right = insert(root->right, a, d);
        }
        else
        {
            root->left = insert(root->left, a, d);
        }
    }
    else if (a + d < root->sum)
    {
        root->left = insert(root->left, a, d);
    }
    else
    {
        root->right = insert(root->right, a, d);
    }
    return root;
}

node *find(node *root, int a, int d)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->a == a && root->d == d)
    {
        return root;
    }
    if (a + d < root->sum || (a + d == root->sum && a < root->a))
    {
        return find(root->left, a, d);
    }
    else
    {
        return find(root->right, a, d);
    }
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->right);
        printf("%d %d %d\n", root->a, root->d, root->count);
        inorder(root->left);
    }
}

int uniqueCount(node *root)
{
    int unique = 0;
    if (root != NULL)
    {
        unique = uniqueCount(root->left);
        if (root->count > 0)
        {
            unique++;
        }
        unique = unique + uniqueCount(root->right);
    }
    return unique;
}

int main()
{
    int n;
    scanf("%d", &n);
    node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        int a, d;
        scanf("%d %d", &a, &d);
        root = insert(root, a, d);
    }

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++)
    {
        char op[10];
        int a1, d1, a2, d2;
        scanf("%s", op);
        scanf("%d %d %d %d", &a1, &d1, &a2, &d2);

        if (op[0] == 'T')
        {
            int trade = 0;
            node *request = NULL;

            if (a2 == -1 && d2 == -1)
            {
                trade = 1;
            }
            else
            {
                request = find(root, a2, d2);
                if (request == NULL || request->count < 2)
                {
                    trade = 0;
                }
                else
                {
                    node *offer = find(root, a1, d1);
                    if (offer == NULL)
                    {
                        trade = 1;
                    }
                    else
                    {
                        if (a1 + d1 > a2 + d2 )
                        {
                            trade = 1;
                        }
                        else if(a1+d1 == a2+d2)
                        {
                            if(a1>a2) trade = 1;
                            else trade = 0;
                        }
                        else
                        {
                            trade = 0;
                        }
                        
                    }
                }
            }

            printf("%d\n", trade);
            if (trade == 1)
            {
                if (request)
                {
                    request->count--;
                }
                root = insert(root, a1, d1);
            }
        }
    }

    int unique = uniqueCount(root);
    printf("%d\n", unique);
    inorder(root);

    return 0;
}
