#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int count;
} node;

node *create(int val)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->count = 1;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int height(node *root)
{
    if (root == NULL)
        return -1;
    int lh = height(root->left);
    int rh = height(root->right);
    int h = (lh > rh) ? lh : rh;
    return h + 1;
}

int depth(node *root, int x)
{
    int depth = 0;
    node *current = root;
    while (current != NULL)
    {
        if (x == current->data)
            return depth;
        else if (x < current->data)
            current = current->left;
        else
            current = current->right;
        depth++;
    }
    return -1;
}


int count(node *root)
{
    if (root == NULL)
        return 0;
    else
        return root->count;
}


node *insert(node *root, int x)
{
    if (root == NULL)
        return create(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    root->count = 1 + count(root->left) + count(root->right);
    return root;
}

void inorder(node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

node *findMin(node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

node *delete(node *root, int x)
{
    if (root == NULL)
        return NULL;
    
    if (x < root->data)
        root->left = delete (root->left, x);
    else if (x > root->data)
        root->right = delete (root->right, x);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
    }
    root->count = 1 + count(root->left) + count(root->right);
    return root;
}

node *lca(node *root, int x, int y)
{
    if (root == NULL)
        return NULL;
    if (root->data > x && root->data > y)
        return lca(root->left, x, y);
    if (root->data < x && root->data < y)
        return lca(root->right, x, y);
    return root;
}

int countless(node *root, int x)
{
    if (root == NULL)
        return 0;
    
    if (root->data < x)
        return 1 + count(root->left) + countless(root->right, x);
    else
        return countless(root->left, x);
}

int countbw(node *root, int l, int r)
{
    int left, right;
    left = countless(root, l);
    right = countless(root, r + 1);
    return right - left;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    node *root = NULL;
    int x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }
    for (int i = 0; i < q; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int x;
            scanf("%d", &x);
            root = insert(root, x);
        }
        else if (op == 2)
        {
            int x;
            scanf("%d", &x);
            root = delete (root, x);
        }
        else if (op == 3)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            int num = countbw(root, l, r);
            printf("%d\n", num);
        }
    }
    return 0;
}