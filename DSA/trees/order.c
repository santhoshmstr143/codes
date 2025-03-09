#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *newNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void inorderRec(node *root)
{
    if (root != NULL)
    {
        inorderRec(root->left);
        printf("%d ", root->data);
        inorderRec(root->right);
    }
    else return;
}

void preorderRec(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderRec(root->left);
        preorderRec(root->right);
    }
}

void postorderRec(node *root)
{
    if (root != NULL)
    {
        postorderRec(root->left);
        postorderRec(root->right);
        printf("%d ", root->data);
    }
}

void levelorder(node *root)
{
    if (root == NULL)
        return;

    node *lol[100];
    int front = 0, rear = 0;
    lol[rear++] = root;

    while (front < rear)
    {
        node *temp = lol[front++];
        printf("%d ", temp->data);
        if (temp->left)
            lol[rear++] = temp->left;
        if (temp->right)
            lol[rear++] = temp->right;
    }
}

void inorderIterative(node *root)
{
    if (root == NULL)
        return;
    node *stack[100];
    int top = -1;
    node *curr = root;
    while (curr != NULL || top != -1)
    {
        while (curr != NULL)
        {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

void preorderIterative(node *root)
{
    if (root == NULL)
        return;
    node *stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1)
    {
        node *curr = stack[top--];
        printf("%d ", curr->data);
        if (curr->right)
            stack[++top] = curr->right;
        if (curr->left)
            stack[++top] = curr->left;
    }
}

void postorderIterative(node *root)
{
    if (root == NULL)
        return;
    node *stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1)
    {
        node *curr = stack1[top1--];
        stack2[++top2] = curr;
        if (curr->left)
            stack1[++top1] = curr->left;
        if (curr->right)
            stack1[++top1] = curr->right;
    }
    while (top2 != -1)
    {
        printf("%d ", stack2[top2--]->data);
    }
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Inorder Traversal: ");
    inorderRec(root);
    printf("...");
    inorderIterative(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderRec(root);
    printf("...");
    preorderIterative(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderRec(root);
    printf("...");
    postorderIterative(root);
    printf("\n");

    printf("Level Order Traversal: ");
    levelorder(root);
    printf("\n");

    return 0;
}
