#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node {
    int data;
    struct Node* parent;  // Pointer to the parent (not head, for union-find)
    int size;             // Size of the set for union by size
} Node;

// Function to create a new node (singleton set)
Node* makeSet(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->parent = newNode;  // Initially, the node is its own parent
    newNode->size = 1;          // Initially, size of set is 1
    return newNode;
}

// Function to find the representative of the set with path compression
Node* find(Node* node) {
    if (node->parent != node) {
        node->parent = find(node->parent);  // Path compression
    }
    return node->parent;
}

// Function to union two sets using union by size
void unionSets(Node* node1, Node* node2) {
    Node* root1 = find(node1);
    Node* root2 = find(node2);

    if (root1 != root2) {
        // Union by size: attach smaller tree to larger tree
        if (root1->size < root2->size) {
            root1->parent = root2;
            root2->size += root1->size;
        } else {
            root2->parent = root1;
            root1->size += root2->size;
        }
    }
}

// Function to print all sets
void printSet(Node** set, int setSize) {
    Node* representatives[setSize];
    int representativeCount = 0;

    for (int i = 0; i < setSize; i++) {
        Node* rep = find(set[i]);
        int found = 0;
        for (int j = 0; j < representativeCount; j++) {
            if (representatives[j] == rep) {
                found = 1;
                break;
            }
        }
        if (!found) {
            representatives[representativeCount++] = rep;
            printf("%d", rep->data);
            for (int j = 0; j < setSize; j++) {
                if (find(set[j]) == rep) {
                    printf("%d", set[j]->data);
                }
            }
            printf("\n");
        }
    }
}

int main() {
    int numSets, numElements, data, choice, set1Index, element1Index, set2Index, element2Index;
    Node*** sets = NULL;
    int* setSizes = NULL;

    printf("Enter the number of sets: ");
    scanf("%d", &numSets);

    // Allocate memory for the sets array and set sizes
    sets = (Node***)malloc(numSets * sizeof(Node**));
    setSizes = (int*)malloc(numSets * sizeof(int));

    // Create sets based on user input
    for (int i = 0; i < numSets; i++) {
        printf("Enter the number of elements in set %d: ", i + 1);
        scanf("%d", &numElements);
        setSizes[i] = numElements;
        sets[i] = (Node**)malloc(numElements * sizeof(Node*));

        for (int j = 0; j < numElements; j++) {
            printf("Enter element %d of set %d: ", j + 1, i + 1);
            scanf("%d", &data);
            sets[i][j] = makeSet(data);
        }
    }

    // Perform union and find operations
    do {
        printf("\nMenu:\n");
        printf("1. Union of two elements\n");
        printf("2. Find representative of an element\n");
        printf("3. Print all sets\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter indices of two elements to perform union:\n");
                printf("Set1 and Element Index (set_index element_index): ");
                scanf("%d %d", &set1Index, &element1Index);
                printf("Set2 and Element Index (set_index element_index): ");
                scanf("%d %d", &set2Index, &element2Index);

                if (set1Index > 0 && set1Index <= numSets &&
                    element1Index > 0 && element1Index <= setSizes[set1Index - 1] &&
                    set2Index > 0 && set2Index <= numSets &&
                    element2Index > 0 && element2Index <= setSizes[set2Index - 1]) {
                    unionSets(sets[set1Index - 1][element1Index - 1], sets[set2Index - 1][element2Index - 1]);
                    printf("Union completed.\n");
                } else {
                    printf("Invalid indices.\n");
                }
                break;

            case 2:
                printf("Enter the set index and element index to find representative (set_index element_index): ");
                scanf("%d %d", &set1Index, &element1Index);
                if (set1Index > 0 && set1Index <= numSets &&
                    element1Index > 0 && element1Index <= setSizes[set1Index - 1]) {
                    printf("Representative: %d\n", find(sets[set1Index - 1][element1Index - 1])->data);
                } else {
                    printf("Invalid indices.\n");
                }
                break;

            case 3:
                printf("Printing all sets:\n");
                for (int i = 0; i < numSets; i++) {
                    printf("set %d:", i + 1);
                    printSet(sets[i], setSizes[i]);
                }
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Free memory
    for (int i = 0; i < numSets; i++) {
        for (int j = 0; j < setSizes[i]; j++) {
            free(sets[i][j]);
        }
        free(sets[i]);
    }

    free(sets);
    free(setSizes);

    return 0;
}
