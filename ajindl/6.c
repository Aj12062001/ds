#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct {
    int elements[MAX_SIZE];  
    int size;
    int bitString[MAX_SIZE]; 
} Set;

void getUniversalSet();
void getSet(Set *set);
int checkSetInUniversal(Set *set);
void generateBitStrings(Set *setA, Set *setB);
void setUnion(Set *setA, Set *setB);
void setIntersection(Set *setA, Set *setB);
void setDifferenceAminusB(Set *setA, Set *setB);
void setDifferenceBminusA(Set *setA, Set *setB);
void printBitString(int arr[], int size);
void printSetFromBitString(int arr[], int size);

int superSet[MAX_SIZE], superSetSize = 0;

void getUniversalSet() {
    printf("Enter Universal Set Size (max %d): ", MAX_SIZE);
    scanf("%d", &superSetSize);
    if (superSetSize > MAX_SIZE) {
        printf("Error: Size exceeds maximum limit.\n");
        exit(1);
    }

    printf("Enter %d elements for the Universal Set:\n", superSetSize);
    for (int i = 0; i < superSetSize; i++) {
        printf("%d: ", i + 1);
        scanf("%d", &superSet[i]);
    }
}

void getSet(Set *set) {
    printf("Enter Set Size (max %d): ", superSetSize);
    scanf("%d", &set->size);
    if (set->size > superSetSize) {
        printf("Error: Set size cannot exceed Universal Set size.\n");
        exit(1);
    }

    printf("Enter %d elements (must be in the Universal Set):\n", set->size);
    for (int i = 0; i < set->size; i++) {
        printf("%d: ", i + 1);
        scanf("%d", &set->elements[i]);
    }
}

int checkSetInUniversal(Set *set) {
    for (int i = 0; i < set->size; i++) {
        int found = 0;
        for (int j = 0; j < superSetSize; j++) {
            if (set->elements[i] == superSet[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Error: Element %d is not in the Universal Set. Please enter the set again.\n", set->elements[i]);
            return 0;
        }
    }
    return 1;
}

void generateBitStrings(Set *setA, Set *setB) {
    for (int i = 0; i < superSetSize; i++) {
        setA->bitString[i] = 0;
        setB->bitString[i] = 0;
    }

    for (int i = 0; i < setA->size; i++) {
        for (int j = 0; j < superSetSize; j++) {
            if (setA->elements[i] == superSet[j]) {
                setA->bitString[j] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < setB->size; i++) {
        for (int j = 0; j < superSetSize; j++) {
            if (setB->elements[i] == superSet[j]) {
                setB->bitString[j] = 1;
                break;
            }
        }
    }

    printf("Set A Bit String: ");
    printBitString(setA->bitString, superSetSize);
    printf("Set B Bit String: ");
    printBitString(setB->bitString, superSetSize);
}

void setUnion(Set *setA, Set *setB) {
    int bitStringUnion[MAX_SIZE];
    for (int i = 0; i < superSetSize; i++) {
        bitStringUnion[i] = setA->bitString[i] | setB->bitString[i];
    }
    printf("Union: ");
    printBitString(bitStringUnion, superSetSize);
    printf("Union Result (Values): ");
    printSetFromBitString(bitStringUnion, superSetSize);
}

void setIntersection(Set *setA, Set *setB) {
    int bitStringIntersection[MAX_SIZE];
    for (int i = 0; i < superSetSize; i++) {
        bitStringIntersection[i] = setA->bitString[i] & setB->bitString[i];
    }
    printf("Intersection: ");
    printBitString(bitStringIntersection, superSetSize);
    printf("Intersection Result (Values): ");
    printSetFromBitString(bitStringIntersection, superSetSize);
}

void setDifferenceAminusB(Set *setA, Set *setB) {
    int bitStringDifferenceAminusB[MAX_SIZE];
    for (int i = 0; i < superSetSize; i++) {
        bitStringDifferenceAminusB[i] = setA->bitString[i] & (1 - setB->bitString[i]);
    }
    printf("Difference (A - B): ");
    printBitString(bitStringDifferenceAminusB, superSetSize);
    printf("Difference Result (A - B, Values): ");
    printSetFromBitString(bitStringDifferenceAminusB, superSetSize);
}

void setDifferenceBminusA(Set *setA, Set *setB) {
    int bitStringDifferenceBminusA[MAX_SIZE];
    for (int i = 0; i < superSetSize; i++) {
        bitStringDifferenceBminusA[i] = setB->bitString[i] & (1 - setA->bitString[i]);
    }
    printf("Difference (B - A): ");
    printBitString(bitStringDifferenceBminusA, superSetSize);
    printf("Difference Result (B - A, Values): ");
    printSetFromBitString(bitStringDifferenceBminusA, superSetSize);
}

void printBitString(int arr[], int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

void printSetFromBitString(int arr[], int size) {
    int first = 1;
    printf("{");
    for (int i = 0; i < size; i++) {
        if (arr[i] == 1) {
            if (!first) {
                printf(", ");
            }
            printf("%d", superSet[i]);
            first = 0;
        }
    }
    printf("}\n");
}

int main() {
    Set setA, setB;
    int choice;

    getUniversalSet();

    do {
        getSet(&setA);
    } while (checkSetInUniversal(&setA) == 0);

    do {
        getSet(&setB);
    } while (checkSetInUniversal(&setB) == 0);

    generateBitStrings(&setA, &setB);

    do {
        printf("\nChoose an operation:\n");
        printf("1. Union of A and B\n");
        printf("2. Intersection of A and B\n");
        printf("3. Difference (A - B)\n");
        printf("4. Difference (B - A)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                setUnion(&setA, &setB);
                break;
            case 2:
                setIntersection(&setA, &setB);
                break;
            case 3:
                setDifferenceAminusB(&setA, &setB);
                break;
            case 4:
                setDifferenceBminusA(&setA, &setB);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
