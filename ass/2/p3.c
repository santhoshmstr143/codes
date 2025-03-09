#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct node
{
    int a;
    int d;
    int count;
    int size;
    struct node *left;
    struct node *right;
    struct node *parent;
    int sum;
} node;

node *create(int a, int d)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->a = a;
    temp->d = d;
    temp->count = 1;
    temp->size = 1;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    temp->sum = a + d;
    return temp;
}

int Size(node *root)
{
    if (root == NULL)
        return 0;
    return root->size;
}

node *insert(node *root, int a, int d, node *parent)
{
    if (root == NULL)
    {
        node *newNode = create(a, d);
        newNode->parent = parent;
        return newNode;
    }
    if (a + d == root->sum)
    {
        if (a == root->a && d == root->d)
        {
            root->count++;
        }
        else if (a > root->a)
        {
            root->right = insert(root->right, a, d, root);
        }
        else
        {
            root->left = insert(root->left, a, d, root);
        }
    }
    else if (a + d < root->sum)
    {
        root->left = insert(root->left, a, d, root);
    }
    else
    {
        root->right = insert(root->right, a, d, root);
    }
    root->size = root->count + Size(root->left) + Size(root->right);
    return root;
}

node *find(node *root, int a, int d)
{
    if (root == NULL)
        return NULL;
    if (root->a == a && root->d == d)
        return root;
    if (a + d < root->sum || (a + d == root->sum && a < root->a))
        return find(root->left, a, d);
    else
        return find(root->right, a, d);
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
            unique++;
        unique = unique + uniqueCount(root->right);
    }
    return unique;
}

node *kth(node *root, int k)
{
    if (root == NULL)
        return NULL;
    int left = Size(root->left);
    if (k <= left)
        return kth(root->left, k);
    else if (k > left && k <= left + root->count)
        return root;
    else
        return kth(root->right, k - left - root->count);
}

int total(node *root)
{
    if (root == NULL)
        return 0;
    return root->size;
}

void updateParentSize(node *cur, int change)
{
    while (cur != NULL)
    {
        cur->size += change;
        cur = cur->parent;
    }
}

void unsort(int a[][2], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);  
        int temp1 = a[i][0], temp2 = a[i][1];

        a[i][0] = a[j][0];
        a[i][1] = a[j][1];

        a[j][0] = temp1;
        a[j][1] = temp2;
    }
}


int main()
{
    int n;
    scanf("%d", &n);
    node *root = NULL;
    int arr[n][2];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }
    unsort(arr, n);


    for (int i = 0; i < n; i++)
    {
        int a, d;
        a = arr[i][0];
        d = arr[i][1];
        root = insert(root, a, d, NULL);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        char op[10];
        scanf("%s", op);
        if (op[0] == 'T')
        {
            int a1, d1, a2, d2;
            scanf("%d %d %d %d", &a1, &d1, &a2, &d2);
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
                        if (a1 + d1 > a2 + d2)
                            trade = 1;
                        else if (a1 + d1 == a2 + d2)
                            trade = (a1 > a2) ? 1 : 0;
                        else
                            trade = 0;
                    }
                }
            }
            printf("%d\n", trade);
            if (trade == 1)
            {
                if (request)
                {
                    request->count--;
                    updateParentSize(request, -1);
                }
                root = insert(root, a1, d1, NULL);
            }
        }
        else if (op[0] == 'K')
        {
            int k;
            scanf("%d", &k);
            int l = total(root);
            if (k > l || k <= 0)
            {
                printf("-1\n");
            }
            else
            {
                node *ans = kth(root, l - k + 1);
                if (ans != NULL)
                    printf("%d %d %d\n", ans->a, ans->d, ans->count);
                else
                    printf("-1\n");
            }
        }
    }
    int unique = uniqueCount(root);
    printf("%d\n", unique);
    inorder(root);
    return 0;
}