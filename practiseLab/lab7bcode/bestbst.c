#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef struct node
{
    long long int data;
    struct node *left;
    struct node *right;
} node;
void merge(long long int a[], long long int n, long long int start, long long int end)
{
    if (start == end)
    {
        return;
    }
    long long int mid = (start + end) / 2;
    merge(a, n, start, mid);
    merge(a, n, mid + 1, end);

    long long int l = start, r = mid + 1, i = 0;
    long long int temp[end - start + 1];

    while (l <= mid || r <= end)
    {
        if (r > end || (l <= mid && a[l] < a[r]))
        {
            temp[i] = a[l];
            l++;
        }
        else
        {
            temp[i] = a[r];
            r++;
        }
        i++;
    }
    for (long long int j = 0; j < end - start + 1; j++)
    {
        a[j + start] = temp[j];
    }
}
node *build(long long int a[], long long int start, long long int end)
{
    if (start > end)
        return NULL;
    long long int mid= (start+end)/2;
    node *root = (node *)malloc(sizeof(node));
    root->data = a[mid];
    root->left = NULL;
    root->right = NULL;
    root->left = build(a, start, mid - 1);
    root->right = build(a, mid + 1, end);
    return root;
}
void preorder(node *root)
{
    if(root)
    {
        printf("%lld ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    long long int n;
    scanf("%lld", &n);
    long long int a[n];
    for (long long int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    merge(a, n, 0, n - 1);
    node *root = build(a, 0, n - 1);
    preorder(root);
    printf("\n");
    return 0;
}