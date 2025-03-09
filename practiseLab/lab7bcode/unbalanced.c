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
node *parent = NULL;
node *tail = NULL;
node *create(int val)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int l = 0;

int height(node *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    int h = (lh > rh) ? lh : rh;
    return h + 1;
}

node *insert(node *root, int x)
{

    if (root == NULL)
    {
        root = create(x);
        parent = root;
        tail = root;
        return root;
    }
    if (tail->data < x)
    {
        tail->right = create(x);
        tail = tail->right;
        return root;
    }
    if (parent->data > x)
    {
        parent->left = create(x);
        parent = parent->left;
        tail = parent;
        return root;
    }
    node *dup = parent;
    while (1)
    {
        if (dup->data > x)
        {
            if (dup->left == NULL)
            {
                dup->left = create(x);
                return root;
            }
            dup = dup->left;
        }
        else
        {
            if (dup->right == NULL)
            {
                dup->right = create(x);
                return root;
            }
            dup = dup->right;
        }
    }
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

int print(node *root)
{
    if(root == NULL) return 0;

    int lh = print(root->left);
    int rh = print(root->right);

    if(lh > rh)
    {
        if(lh - rh > 1)
        {
            l++;
        }
        return lh + 1;
    }
    else{
        if(rh - lh > 1)
        {
            l++;
        }
        return rh + 1;
    }

}

int main()
{
    int n;
    scanf("%d", &n);
    node *root = NULL;
    int a[n + 1];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        root = insert(root, a[i]);
    }
    // inorder(root);
    //printf("\n%d ",root->left->right->data);
    print(root);
    printf("%d\n", l);
    return 0;
}