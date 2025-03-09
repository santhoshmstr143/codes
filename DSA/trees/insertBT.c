#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;
struct Node *newNode(int item)
{
    struct Node *temp =
        (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

node *insertRecBST(node *root, int key)
{
    if (root == NULL)
        return newNode(key);
    if (key == root->data)
        return root;
    if (key > root->data)
    {
        root->right = insertRecBST(root->right, key);
    }
    else
    {
        root->left = insertRecBST(root->left, key);
    }
    return root;
}

node *insertIt(node *root, int key)
{
    node *temp = newNode(key);
    if (root == NULL)
        return temp;
    node *par = NULL, *cur = NULL;
    cur = root;
    while (cur != NULL)
    {
        par = cur;
        if (key < cur->data)
        {
            cur = cur->left;
        }
        else if (key > cur->data)
        {
            cur = cur->right;
        }
        else
        {
            return root;
        }
    }
    if (key < par->data)
    {
        par->left = temp;
    }
    else
    {
        par->right = temp;
    }
    return root;
}

int main()
{
    struct Node *root = newNode(50);
    root = insertIt(root, 30);
    root = insertIt(root, 20);
    root = insertIt(root, 40);
    root = insertIt(root, 70);
    root = insertIt(root, 60);
    root = insertIt(root, 80);

    // Print inorder traversal of the BST
    inorder(root);
    return 0;
}