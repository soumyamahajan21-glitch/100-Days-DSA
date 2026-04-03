#include <stdio.h>
#include <stdlib.h>

// Definition of tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Queue structure
struct Queue {
    int front, rear;
    int size;
    struct Node** array;
};

// Create queue
struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = size;
    queue->array = (struct Node**)malloc(size * sizeof(struct Node*));
    return queue;
}

// Check if queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->rear < queue->front);
}

// Enqueue
void enqueue(struct Queue* queue, struct Node* node) {
    queue->array[++queue->rear] = node;
}

// Dequeue
struct Node* dequeue(struct Queue* queue) {
    return queue->array[queue->front++];
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue* queue = createQueue(100);

    enqueue(queue, root);

    while (!isEmpty(queue)) {
        struct Node* temp = dequeue(queue);
        printf("%d ", temp->data);

        if (temp->left)
            enqueue(queue, temp->left);

        if (temp->right)
            enqueue(queue, temp->right);
    }
}

// Driver code
int main() {
    /*
            1
           / \
          2   3
         / \    \
        4   5    6
    */

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Level Order Traversal:\n");
    levelOrder(root);

    return 0;
}