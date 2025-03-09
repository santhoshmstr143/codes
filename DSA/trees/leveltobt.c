#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* buildBST(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    TreeNode* root = createNode(arr[0]);
    TreeNode** queue = (TreeNode**)malloc(n * sizeof(TreeNode*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        TreeNode* temp = queue[front++];
        
        if (i < n && arr[i] != -1) {
            temp->left = createNode(arr[i]);
            queue[rear++] = temp->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            temp->right = createNode(arr[i]);
            queue[rear++] = temp->right;
        }
        i++;
    }

    free(queue);
    return root;
}

void inorder(TreeNode* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    int levelOrder[] = {10, 5, 20, 3, -1, 15, 25};
    int n = sizeof(levelOrder) / sizeof(levelOrder[0]);

    TreeNode* root = buildBST(levelOrder, n);
    
    printf("In-order Traversal of BST: ");
    inorder(root);
    printf("\n");

    return 0;
}
