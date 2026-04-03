#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

struct QNode {
    struct Node* node;
    int hd;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

void verticalOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct QNode queue[1000];
    int front = 0, rear = 0;

    int hd[1000], values[1000];
    int count = 0;

    queue[rear++] = (struct QNode){root, 0};

    while (front < rear) {
        struct QNode temp = queue[front++];

        hd[count] = temp.hd;
        values[count] = temp.node->val;
        count++;

        if (temp.node->left)
            queue[rear++] = (struct QNode){temp.node->left, temp.hd - 1};

        if (temp.node->right)
            queue[rear++] = (struct QNode){temp.node->right, temp.hd + 1};
    }

    int min = hd[0], max = hd[0];
    for (int i = 1; i < count; i++) {
        if (hd[i] < min) min = hd[i];
        if (hd[i] > max) max = hd[i];
    }

    for (int i = min; i <= max; i++) {
        for (int j = 0; j < count; j++) {
            if (hd[j] == i)
                printf("%d ", values[j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}