#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0)
        return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        nodes[i] = newNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (2*i + 1 < n)
            nodes[i]->left = nodes[2*i + 1];
        if (2*i + 2 < n)
            nodes[i]->right = nodes[2*i + 2];
    }

    return nodes[0];
}

int isMinHeap(struct Node* root) {
    if (root == NULL)
        return 1;

    if (root->left != NULL) {
        if (root->val > root->left->val)
            return 0;
    }

    if (root->right != NULL) {
        if (root->val > root->right->val)
            return 0;
    }

    return isMinHeap(root->left) && isMinHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if (isMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}