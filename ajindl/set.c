#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 10  // Define the initial size for the dynamic array

// Define the Set structure
struct Set {
    int *elements; // Dynamic array to store elements
    int size;      // Current number of elements
    int capacity;  // Current capacity of the array
};

// Function to create a new set
struct Set* createSet() {
    struct Set* set = (struct Set*)malloc(sizeof(struct Set));
    set->elements = (int*)malloc(INITIAL_SIZE * sizeof(int));
    set->size = 0;
    set->capacity = INITIAL_SIZE;
    return set;
}

// Function to check if an element exists in the set
int exists(struct Set* set, int value) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == value) {
            return 1; // Element exists
        }
    }
    return 0; // Element does not exist
}

// Function to add an element to the set
void add(struct Set* set, int value) {
    if (!exists(set, value)) {
        if (set->size == set->capacity) {
            set->capacity *= 2;  // Double the capacity if full
            set->elements = (int*)realloc(set->elements, set->capacity * sizeof(int));
        }
        set->elements[set->size++] = value;
    }
}

// Function to display the elements in the set
void displaySet(struct Set* set) {
    if (set->size == 0) {
        printf("The set is empty.\n");
        return;
    }
    printf("{ ");
    for (int i = 0; i < set->size; i++) {
        printf("%d ", set->elements[i]);
    }
    printf("}\n");
}

// Function for set union
struct Set* unionSets(struct Set* setA, struct Set* setB) {
    struct Set* resultSet = createSet();
    for (int i = 0; i < setA->size; i++) {
        add(resultSet, setA->elements[i]);
    }
    for (int i = 0; i < setB->size; i++) {
        add(resultSet, setB->elements[i]);
    }
    return resultSet;
}

// Function for set intersection
struct Set* intersectionSets(struct Set* setA, struct Set* setB) {
    struct Set* resultSet = createSet();
    for (int i = 0; i < setA->size; i++) {
        if (exists(setB, setA->elements[i])) {
            add(resultSet, setA->elements[i]);
        }
    }
    return resultSet;
}

// Function for set difference
struct Set* differenceSets(struct Set* setA, struct Set* setB) {
    struct Set* resultSet = createSet();
    for (int i = 0; i < setA->size; i++) {
        if (!exists(setB, setA->elements[i])) {
            add(resultSet, setA->elements[i]);
        }
    }
    return resultSet;
}

// Function to free the memory allocated for the set
void freeSet(struct Set* set) {
    free(set->elements);
    free(set);
}

// Main function to demonstrate set operations
int main() {
    struct Set* setA = createSet();
    struct Set* setB = createSet();
    int value, nA, nB;

    // Input values for Set A
    printf("Enter the number of elements for setA: ");
    scanf("%d", &nA);
    printf("Enter the elements for setA:\n");
    for (int i = 0; i < nA; i++) {
        scanf("%d", &value);
        add(setA, value);
    }
    displaySet(setA);

    // Input values for Set B
    printf("Enter the number of elements for setB: ");
    scanf("%d", &nB);
    printf("Enter the elements for setB:\n");
    for (int i = 0; i < nB; i++) {
        scanf("%d", &value);
        add(setB, value);
    }
    displaySet(setB);

    // Perform union
    struct Set* unionSet = unionSets(setA, setB);
    printf("Union of A and B: ");
    displaySet(unionSet);

    // Perform intersection
    struct Set* intersectionSet = intersectionSets(setA, setB);
    printf("Intersection of A and B: ");
    displaySet(intersectionSet);

    // Perform difference (A - B)
    struct Set* differenceSet = differenceSets(setA, setB);
    printf("Difference of A - B: ");
    displaySet(differenceSet);

    // Free memory
    freeSet(setA);
    freeSet(setB);
    freeSet(unionSet);
    freeSet(intersectionSet);
    freeSet(differenceSet);

    return 0;
}

