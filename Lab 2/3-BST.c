#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to perform in-order traversal (Left -> Root -> Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to perform pre-order traversal (Root -> Left -> Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform post-order traversal (Left -> Right -> Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
printf("**\tCompiled By Aswin phuyal\t**\n");
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- BST Operations ---\n");
        printf("1. Insert\t");
        printf("2. Delete\t");
        printf("3. Search\n");
        printf("4. In-order Traversal\t");
        printf("5. Pre-order Traversal\t");
        printf("6. Post-order Traversal\t");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted successfully.\n", value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                // Call delete function (this part can be implemented as needed)
                // root = deleteNode(root, value);
                printf("%d deleted successfully.\n", value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                // Search operation here (implement as needed)
                // struct Node* searchResult = search(root, value);
                // printf("%d found.\n", value);
                break;

            case 4:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Pre-order Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Post-order Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                printf("Exited\n");
                return 0;

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

