#include <stdio.h>
#include <stdlib.h>
 
// Define a structure for a binary tree node
struct BinaryTreeNode {
    int key;
    struct BinaryTreeNode *left, *right;
};
 
// Function to create a new node with a given value
struct BinaryTreeNode* newNodeCreate(int value)
{
    struct BinaryTreeNode* temp
        = (struct BinaryTreeNode*)malloc(
            sizeof(struct BinaryTreeNode));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Function to search for a node with a specific key in the
// tree
struct BinaryTreeNode*
searchNode(struct BinaryTreeNode* root, int target)
{
    if (root == NULL || root->key == target) {
        return root;
    }
    if (root->key < target) {
        return searchNode(root->right, target);
    }
    return searchNode(root->left, target);
}
 
// Function to insert a node with a specific value in the
// tree
struct BinaryTreeNode*
insertNode(struct BinaryTreeNode* node, int value)
{
    if (node == NULL) {
        return newNodeCreate(value);
    }

    if (value < node->key) {
        node->left = insertNode(node->left, value);
    }
    else if (value > node->key) {
        node->right = insertNode(node->right, value);
    }
    printf("%d the value is inserted",value);
   return node;

}
 
// Function to perform post-order traversal
void postOrder(struct BinaryTreeNode* root)
{
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->key);
    }
}
 
// Function to perform in-order traversal
void inOrder(struct BinaryTreeNode* root)
{
    if (root != NULL) {
        inOrder(root->left);
        printf(" %d ", root->key);
        inOrder(root->right);
    }
}
 
// Function to perform pre-order traversal
void preOrder(struct BinaryTreeNode* root)
{
    if (root != NULL) {
        printf(" %d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
struct BinaryTreeNode* findMin (struct BinaryTreeNode* root)
{
	struct BinaryTreeNode*current=root;
	while(current && current->left!=NULL)
		{
			return current;

}		}
// Function to delete a node from the tree
struct BinaryTreeNode* delete (struct BinaryTreeNode* root,
                               int x)
{
    if (root == NULL)
        return NULL;
 
    if (x > root->key) {
        root->right = delete (root->right, x);
    }
    else if (x < root->key) {
        root->left = delete (root->left, x);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else {
            struct BinaryTreeNode* temp
                = findMin(root->right);
            root->key = temp->key;
            root->right = delete (root->right, temp->key);
        }
    }
    return root;
}


int main()
{
        struct BinaryTreeNode* root = NULL;
	 int ch=0,x,value,target;
        while(ch!= 6)
        {
                printf("\nChoose any one option from list ...\n");
                printf("\n1 insertion to binary tree\n2.post-order traversal\n3.pre-order\n4.inorder\n5.search\n6.delete\n7.exit");
                printf("\nSelect the desired choice: \n");
                scanf("\n%d",&ch);
                switch(ch)
                {
			case 1:printf("enter the data: ");
				scanf("%d",&value);
				root=insertNode(root,value);
				break;
			case 2: printf("post-order");
				postOrder(root);
				printf("\n");
				break;
			case 3:printf("pre-order");
                                preOrder(root); 
                                printf("\n");
                                break;
			case 4:printf("In-order");
                                inOrder(root); 
                                printf("\n");
                                break;
			case 5:printf("enter value to search: ");
				scanf("%d",&target);
				if (searchNode(root,target) != NULL) {
        			printf("%d found",target);
    				}
    				else {
        				printf("%d not found",target);
    					}
				break;
 			case 6:printf("enter the value to delete: ");
				scanf("%d",&x);
				struct BinaryTreeNode* temp = delete (root,x);
    				printf("After Delete: \n");
				 printf("\n");
				inOrder(root);
				break;
			case 7:exit(0);
				break;

			default:printf("enter correct choice..");
		}
	}
return 0;
}
