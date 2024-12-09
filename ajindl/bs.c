#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct BinaryTreeNode {
    int key;
    struct BinaryTreeNode *left, *right;
};

// Function to create a new node with a given value
struct BinaryTreeNode* newNodeCreate(int value) {
    struct BinaryTreeNode* temp = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to search for a node with a specific key in the tree
struct BinaryTreeNode* searchNode(struct BinaryTreeNode* root, int target) {
    if (root == NULL || root->key == target) {
        return root;
    }
    if (root->key < target) {
        return searchNode(root->right, target);
    }
    return searchNode(root->left, target);
}

// Function to insert a node with a specific value in the tree
struct BinaryTreeNode* insertNode(struct BinaryTreeNode* node, int value) {
    if (node == NULL) {
        return newNodeCreate(value);
    }
    if (value < node->key) {
        node->left = insertNode(node->left, value);
    } else if (value > node->key) {
        node->right = insertNode(node->right, value);
    }
    return node;
}

// Function to perform post-order traversal
void postOrder(struct BinaryTreeNode* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->key);
    }
}

// Function to perform in-order traversal
void inOrder(struct BinaryTreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf(" %d ", root->key);
        inOrder(root->right);
    }
}

// Function to perform pre-order traversal
void preOrder(struct BinaryTreeNode* root) {
    if (root != NULL) {
        printf(" %d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to find the minimum node in a subtree
struct BinaryTreeNode* findMin(struct BinaryTreeNode* root) {
    struct BinaryTreeNode* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the tree
struct BinaryTreeNode* deleteNode(struct BinaryTreeNode* root, int x) {
    if (root == NULL) {
        return NULL;
    }

    if (x > root->key) {
        root->right = deleteNode(root->right, x);
    } else if (x < root->key) {
        root->left = deleteNode(root->left, x);
    } else {
        // Node with the key found
        if (root->left == NULL) {
            struct BinaryTreeNode* temp = root->right;
            free(root);
            return temp; // Return right child
        } else if (root->right == NULL) {
            struct BinaryTreeNode* temp = root->left;
            free(root);
            return temp; // Return left child
        } else {
            // Node with two children: get the inorder successor
            struct BinaryTreeNode* temp = findMin(root->right);
            root->key = temp->key; // Copy the inorder successor's content to this node
            root->right = deleteNode(root->right, temp->key); // Delete the inorder successor
        }
    }
    return root; // Return the (possibly unchanged) node pointer
}

int main() {
    struct BinaryTreeNode* root = NULL;
    int ch = 0, x, value, target;

    while (ch != 7) {
        printf("\nChoose any one option from list ...\n");
        printf("\n1. Insert into binary tree\n2. Post-order traversal\n3. Pre-order traversal\n4. In-order traversal\n5. Search\n6. Delete\n7. Exit");
        printf("\nSelect the desired choice: \n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("%d has been inserted.\n", value);
                 inOrder(root);
		 break;
            case 2:
                printf("Post-order traversal:");
                postOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-order traversal:");
                preOrder(root); 
                printf("\n");
                break;
            case 4:
                printf("In-order traversal:");
                inOrder(root); 
                printf("\n");
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &target);
                if (searchNode(root, target) != NULL) {
                    printf("%d found\n", target);
                } else {
                    printf("%d not found\n", target);
                }
                break;
            case 6:
                printf("Enter the value to delete: ");
                scanf("%d", &x);
                root = deleteNode(root, x);
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Enter a correct choice.\n");
        }
    }
    return 0;
}
