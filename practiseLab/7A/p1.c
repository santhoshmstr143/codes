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

void inorder(node *cur, node *par)
{
   if (!cur)
      return;
   inorder(cur->left, cur);
   if (par == NULL || ((par->left == cur && par->right == NULL) || (par->right == cur && par->left == NULL)))
      printf("%d ", cur->data);
   inorder(cur->right, cur);
}

int main()
{
   int n;
   scanf("%d", &n);
   int parent[n];
   node *nodes[n];
   for (int i = 0; i < n; i++)
   {
      nodes[i] = create(i);
   }
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &parent[i]);
   }
   node *root = NULL;
   for (int i = 0; i < n; i++)
   {
      if (parent[i] == -1)
         root = nodes[i];
      else
      {
         node *p = nodes[parent[i]];
         if (nodes[i]->data < p->data)
            p->left = nodes[i];
         else
            p->right = nodes[i];
      }
   }
   inorder(root, NULL);
   printf("\n");
   return 0;
}
