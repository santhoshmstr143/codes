#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    long long int data;
    struct node *left;
    struct node *right;
} node;

node *create(int x)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


// **10. Height of the Tree**
int height(node *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

// **1. depth
int Depth(node *root, int key)
{
    int depth = 0;
    node *current = root;
    while (current != NULL)
    {
        if (key == current->data)
            return depth;
        else if (key < current->data)
            current = current->left;
        else
            current = current->right;
        depth++;
    }
    return -1;
}
int diameter(node *root)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);
    int ld = diameter(root->left);
    int rd = diameter(root->right);

    // Maximum of three values: left diameter, right diameter, and path through root
    return max(lh + rh + 1, max(ld, rd));
}


int findlca(int parent[], int n, int a, int b)
{
    int ancestors[n + 1];
    for (int i = 0; i <= n; i++)
        ancestors[i] = 0;
    while (a != -1)
    {
        ancestors[a] = 1;
        a = parent[a];
    }
    while (b != -1)
    {
        if (ancestors[b] == 1)
            return b;
        b = parent[b];
    }
    return -1;
}

void maxsum(node *root, long long int curr, long long int *max)
{
    if (root == NULL)
        return;
    curr += root->data;
    if (curr > *max)
        *max = curr;
    maxsum(root->left, curr, max);
    maxsum(root->right, curr, max);
}
//////////////////////////
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int findMaxPathSum(struct TreeNode* root, int* maxSum) {
    if (root == NULL) return 0;

    int lsum = findMaxPathSum(root->left, maxSum);
    int rsum = findMaxPathSum(root->right, maxSum);
    
    lsum = lsum > 0 ? lsum : 0;
    rsum = rsum > 0 ? rsum : 0;

    int localMax = root->val + lsum + rsum;
    
    if (localMax > *maxSum) {
        *maxSum = localMax;
    }

    return root->val + (lsum > rsum ? lsum : rsum);
}

int maxPathSum(struct TreeNode* root) {
    int maxSum = INT_MIN;
    findMaxPathSum(root, &maxSum);
    return maxSum;
}
//////////////////////////////

// **1. Insert into BST (Recursive)**
node *insert(node *root, int data)
{
    if (root == NULL)
        return create(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// **2. Search in BST**
node *search(node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// **3. Find Minimum Node in BST**
node *findMin(node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

// **4. Delete a Node from BST**
node *deleteNode(node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
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
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// **5. Inorder Traversal (Left, Root, Right)**
void inorder(node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// **6. Preorder Traversal (Root, Left, Right)**
void preorder(node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// **7. Postorder Traversal (Left, Right, Root)**
void postorder(node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// **8. Level Order Traversal (BFS using Queue)**
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
// **9. Zigzag Traversal**
void zigzagPrint(node *root)
{
    if (root == NULL)
        return;
    int capacity = 1000;
    node **stack1 = (node **)malloc(sizeof(node *) * capacity);
    node **stack2 = (node **)malloc(sizeof(node *) * capacity);
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 >= 0 || top2 >= 0)
    {
        while (top1 >= 0)
        {
            node *temp = stack1[top1--];
            printf("%d ", temp->data);
            if (temp->left)
                stack2[++top2] = temp->left;
            if (temp->right)
                stack2[++top2] = temp->right;
        }
        while (top2 >= 0)
        {
            node *temp = stack2[top2--];
            printf("%d ", temp->data);
            if (temp->right)
                stack1[++top1] = temp->right;
            if (temp->left)
                stack1[++top1] = temp->left;
        }
    }
    free(stack1);
    free(stack2);
}

// **11. Count Number of Nodes**
int countNodes(node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// **12. Count Leaf Nodes**
int countLeafNodes(node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// **13. Free the Entire Tree (Memory Management)**
void freeTree(node *root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// **10. K-th Smallest Element**
void findKthSmallest(node *root, int k, int *count, int *result)
{
    if (root == NULL || *count >= k)
        return;
    findKthSmallest(root->left, k, count, result);
    (*count)++;
    if (*count == k)
    {
        *result = root->data;
        return;
    }
    findKthSmallest(root->right, k, count, result);
}

// **12. Check if a tree is a valid BST**
int isValidBSTUtil(node *root, int min, int max)
{
    if (root == NULL)
        return 1;
    if (root->data <= min || root->data >= max)
        return 0;
    return isValidBSTUtil(root->left, min, root->data) &&
           isValidBSTUtil(root->right, root->data, max);
}

int isValidBST(node *root)
{
    return isValidBSTUtil(root, -1000000, 1000000);
}

// **2. Find Inorder Predecessor & Successor**
//    node *pre = NULL, *suc = NULL;
//    findPreSuc(root, &pre, &suc, 65);
//    printf("Predecessor: %d, Successor: %d\n", pre ? pre->data : -1, suc ? suc->data : -1);
void findPreSuc(node *root, node **pre, node **suc, int key)
{
    if (root == NULL)
        return;
    if (root->data == key)
    {
        if (root->left)
        {
            node *temp = root->left;
            while (temp->right)
                temp = temp->right;
            *pre = temp;
        }
        if (root->right)
        {
            node *temp = root->right;
            while (temp->left)
                temp = temp->left;
            *suc = temp;
        }
        return;
    }
    if (root->data > key)
    {
        *suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else
    {
        *pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

// **3. Find Distance Between Two Nodes**
node *findLCA(node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data > n1 && root->data > n2)
        return findLCA(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return findLCA(root->right, n1, n2);
    return root;
}

// **4. Count Nodes in a Given Range [L, R]**
int countNodesInRange(node *root, int L, int R)
{
    if (root == NULL)
        return 0;
    if (root->data >= L && root->data <= R)
        return 1 + countNodesInRange(root->left, L, R) + countNodesInRange(root->right, L, R);
    else if (root->data < L)
        return countNodesInRange(root->right, L, R);
    else
        return countNodesInRange(root->left, L, R);
}

// **5. Find Deepest Node in BST**
node *findDeepest(node *root)
{
    if (root == NULL)
        return NULL;
    node **queue = (node **)malloc(1000 * sizeof(node *));
    int front = 0, rear = 0;
    queue[rear++] = root;
    node *deepest = NULL;
    while (front < rear)
    {
        deepest = queue[front++];
        if (deepest->left)
            queue[rear++] = deepest->left;
        if (deepest->right)
            queue[rear++] = deepest->right;
    }
    free(queue);
    return deepest;
}

// **6. Find the Largest BST in a Binary Tree**
typedef struct
{
    int size;
    int min;
    int max;
    int isBST;
} BSTInfo;

BSTInfo largestBST(node *root)
{
    if (root == NULL)
        return (BSTInfo){0, 1000000, -1000000, 1};
    BSTInfo left = largestBST(root->left);
    BSTInfo right = largestBST(root->right);
    if (left.isBST && right.isBST && root->data > left.max && root->data < right.min)
        return (BSTInfo){left.size + right.size + 1, min(root->data, left.min), max(root->data, right.max), 1};
    return (BSTInfo){max(left.size, right.size), 0, 0, 0};
}

// **7. Find K-th Largest Element in BST**
void findKthLargest(node *root, int k, int *count, int *result)
{
    if (root == NULL || *count >= k)
        return;
    findKthLargest(root->right, k, count, result);
    (*count)++;
    if (*count == k)
    {
        *result = root->data;
        return;
    }
    findKthLargest(root->left, k, count, result);
}

// **8. Print All Paths from Root to Leaf**
void printPath(int path[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", path[i]);
    printf("\n");
}

void printRootToLeaf(node *root, int path[], int pathLen)
{
    if (root == NULL)
        return;
    path[pathLen++] = root->data;
    if (root->left == NULL && root->right == NULL)
        printPath(path, pathLen);
    else
    {
        printRootToLeaf(root->left, path, pathLen);
        printRootToLeaf(root->right, path, pathLen);
    }
}

int findLevel(node *root, int val, int level)
{
    if (root == NULL)
        return -1;
    if (root->data == val)
        return level;
    int l = findLevel(root->left, val, level + 1);
    return (l != -1) ? l : findLevel(root->right, val, level + 1);
}

int findDistance(node *root, int n1, int n2)
{
    node *lca = findLCA(root, n1, n2);
    return findLevel(lca, n1, 0) + findLevel(lca, n2, 0);
}

int main()
{
    long long int q;
    scanf("%lld", &q);
    for (long long int j = 0; j < q; j++)
    {
        long long int n;
        scanf("%lld", &n);
        long long int parent[n + 1];
        node *nodes[n + 1];

        for (long long int i = 1; i <= n; i++)
        {
            scanf("%lld", &parent[i]);
            nodes[i] = create(i);
        }

        for (long long int i = 1; i <= n; i++)
        {
            scanf("%lld", &nodes[i]->data);
        }

        node *root = NULL;
        for (long long int i = 1; i <= n; i++)
        {
            if (parent[i] == -1)
                root = nodes[i];
            else
            {
                node *parentnode = nodes[parent[i]];
                if (parentnode->left == NULL)
                    parentnode->left = nodes[i];
                else
                    parentnode->right = nodes[i];
            }
        }

        long long int l = INT_MIN;
        maxsum(root, 0, &l);
        printf("%lld\n", l);
    }
    return 0;
}

int main()
{
    node *root = NULL;
    int choice, value, k;
    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n7. Level Order Traversal\n8. Zigzag Traversal\n9. Height of Tree\n10. Count Nodes\n11. Count Leaf Nodes\n12. K-th Smallest Element\n13. K-th Largest Element\n14. Find Distance Between Nodes\n15. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(root, value))
                printf("Found\n");
            else
                printf("Not Found\n");
            break;
        case 4:
            inorder(root);
            printf("\n");
            break;
        case 5:
            preorder(root);
            printf("\n");
            break;
        case 6:
            postorder(root);
            printf("\n");
            break;
        case 7:
            levelorder(root);
            printf("\n");
            break;
        case 8:
            zigzagPrint(root);
            printf("\n");
            break;
        case 9:
            printf("Height: %d\n", height(root));
            break;
        case 10:
            printf("Total Nodes: %d\n", countNodes(root));
            break;
        case 11:
            printf("Leaf Nodes: %d\n", countLeafNodes(root));
            break;
        case 12:
            printf("Enter K: ");
            scanf("%d", &k);
            int count = 0, result = -1;
            findKthSmallest(root, k, &count, &result);
            printf("K-th Smallest: %d\n", result);
            break;
        case 13:
            printf("Enter K: ");
            scanf("%d", &k);
            count = 0, result = -1;
            findKthLargest(root, k, &count, &result);
            printf("K-th Largest: %d\n", result);
            break;
        case 14:
            printf("Enter two node values: ");
            int n1, n2;
            scanf("%d %d", &n1, &n2);
            printf("Distance: %d\n", findDistance(root, n1, n2));
            break;
        case 15:
            freeTree(root);
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
