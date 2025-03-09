#include <stdio.h>
#include <stdlib.h>
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

node *insert(node *root, int x)
{
   if (root == NULL)
      return create(x);
   if (x < root->data)
      root->left = insert(root->left, x);
   else if (x > root->data)
      root->right = insert(root->right, x);
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

int main()
{
   int n;
   scanf("%d", &n);
   int parent[n], childCount[n];
   for (int i = 0; i < n; i++)
   {
      childCount[i] = 0;
   }
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &parent[i]);
   }
   for (int i = 0; i < n; i++)
   {
      if (parent[i] != -1)
         childCount[parent[i]]++;
   }
   for (int i = 0; i < n; i++)
   {
      if (parent[i] == -1 || childCount[parent[i]] == 1)
         printf("%d ", i);
   }
   printf("\n");
   return 0;
}