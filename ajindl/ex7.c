#include <stdio.h>

#include <stdlib.h>

// Node structure for linked list

typedef struct Node {

    int data;

    struct Node* next;

    struct Node* head;  // Pointer to the representative of the set

} Node;

// Function to create a new node (singleton set)

Node* makeSet(int data) {

    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;

    newNode->next = NULL;

    newNode->head = newNode;  // The node itself is the representative

    return newNode;

}

// Function to find the representative of the set

Node* find(Node* node) {

    return node->head;

}

// Function to union two sets

void unionSets(Node* node1, Node* node2) {

    Node* head1 = find(node1);

    Node* head2 = find(node2);

    if (head1 != head2) {

        // Merge the second list into the first list

        Node* temp = head1;

        while (temp->next != NULL) {

            temp = temp->next;

        }

        temp->next = head2;  // Append second list to the first

        // Update the head pointer for all nodes in the second list

        temp = head2;

        while (temp != NULL) {

            temp->head = head1;

            temp = temp->next;

        }

    }

}

// Function to print all elements in a set

void printSet(Node** set, int setSize) {

    int* printed = (int*)calloc(setSize, sizeof(int));  // Track printed elements

    for (int i = 0; i < setSize; i++) {

        if (!printed[i]) {  // If this element is not yet printed

            Node* representative = find(set[i]);

            for (int j = 0; j < setSize; j++) {

                if (find(set[j]) == representative) {  // Elements in the same set

                    printf("%d ", set[j]->data);

                    printed[j] = 1;  // Mark as printed

                }

            }

        }

    }

    free(printed);

    printf("\n");

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

                    printf("Set %d: ", i + 1);

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

