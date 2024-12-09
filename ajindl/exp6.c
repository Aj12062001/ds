#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 10

struct Set{
    int *elements;
    int size;
    int capacity;
};
struct Set* createSet() {
    struct Set* set = (struct Set*)malloc(sizeof(struct Set));
    set->elements = (int*)malloc(INITIAL_SIZE * sizeof(int));
    set->size = 0;
    set->capacity = INITIAL_SIZE;
    return set;
}
int universalSet(struct set*,int value){
  printf("Enter the number of elements for setU: ");
    scanf("%d", &nU);
    if(nu>=INITIAL_SIZE)
	{
	  return 0;
	}
    else
    {
    printf("Enter the elements for setU(Universal set):\n");
    for (int i = 0; i < nU; i++)
      {
        scanf("%d", &value);
        add(setU, value);
      }
     }
     displaySet(setU);
}
int checkSetInUniversal(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int found = 0;
        for (int j = 0; j < superSetSize; j++) {
            if (arr[i] == superSet[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Error: Element %d is not in the Universal Set. Please enter the set again.\n", arr[i]);
            return 0;
        }
    }
    return 1;
}

void generateBitStrings() {
    for (int i = 0; i < superSetSize; i++) {
        bitStringA[i] = 0;
        bitStringB[i] = 0;
    }

    for (int i = 0; i < setASize; i++) {
        for (int j = 0; j < superSetSize; j++) {
            if (setA[i] == superSet[j]) {
                bitStringA[j] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < setBSize; i++) {
        for (int j = 0; j < superSetSize; j++) {
            if (setB[i] == superSet[j]) {
                bitStringB[j] = 1;
                break;
            }
        }
    }

    printf("Set A Bit String: ");
    printBitString(bitStringA, superSetSize);
    printf("Set B Bit String: ");
    printBitString(bitStringB, superSetSize);
}

int exists(struct Set* set, int value) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == value) {
            return 1; 
        }
    }
    return 0; 
}
void add(struct Set* set, int value) {
    if (!exists(set, value)) {
        if (set->size == set->capacity) {
            set->capacity *= 2; 
           int* temp = (int*)realloc(set->elements, set->capacity * sizeof(int));
            if (temp == NULL) {
                printf("Memory allocation failed!\n");
                exit(1);
  }
            set->elements = temp;
        }
        set->elements[set->size++] = value;
    }
}

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

struct Set* unionSets(struct Set* setA, struct Set* setB) {
    struct Set* resultSet = createSet();
    for (int i = 0; i < setA->size; i++) {
        add(resultSet, setA->elements[i]);
    }
    for (int i = 0; i < setB->size; i++) {
        add(resultSet, setB->elements[i]);
    }
    return resultSet;
      printSetFromBitString(
}
}
struct Set* intersectionSets(struct Set* setA, struct Set* setB) {
    struct Set* resultSet = createSet();
    for (int i = 0; i < setA->size; i++) {
        if (exists(setB, setA->elements[i])) {
            add(resultSet, setA->elements[i]);
        }
    }
 printBitString(
    printf("Intersection Result (Values): ");
    printSetFromBitString(
   return resultSet;
}

struct Set* differenceA(struct Set* setA, struct Set* setB) {
    struct Set* resultSet = createSet();
    for (int i = 0; i < setA->size; i++) {
        if (!exists(setB, setA->elements[i])) {
            add(resultSet, setA->elements[i]);
        }
    }
  printBitString(
    printf("Difference Result (A - B, Values): ");
    printSetFromBitString(
}
    return resultSet;
}
struct Set* differenceB(struct Set* setB, struct Set* setA) {
    struct Set* resultSet = createSet();
    for (int i = 0; i < setB->size; i++) {
        if (!exists(setA, setB->elements[i])) {
            add(resultSo
et, setB->elements[i]);
        }
    }
    return resultSet;
  printBitString(
    printf("Difference Result (B - A, Values): ");
    printSetFromBitString(
}
}
void freeSet(struct Set* set) {
    free(set->elements);
    free(set);
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
    
    getUniversalSet();

    do {
        printf("Enter Set A Size (max %d): ", superSetSize);
        scanf("%d", &setASize);
        if (setASize > superSetSize) {
            printf("Error: Set A size cannot exceed Universal Set size.\n");
        }
    } while (setASize > superSetSize);

    do {
        getSet(setA, &setASize);
    } while (checkSetInUniversal(setA, setASize) == 0);

    do {
        printf("Enter Set B Size (max %d): ", superSetSize);
        scanf("%d", &setBSize);
        if (setBSize > superSetSize) {
            printf("Error: Set B size cannot exceed Universal Set size.\n");
        }
    } while (setBSize > superSetSize);

    struct Set* setA = createSet();
    struct Set* setB = createSet();
    int value, nA, nB,ch;
    printf("Enter the number of elements for setA: ");
    scanf("%d", &nA);
    printf("Enter the elements for setA:\n");

    for (int i = 0; i < nA; i++) {
        scanf("%d", &value);
        add(setA, value);
    }
    displaySet(setA);

    printf("Enter the number of elements for setB: ");
    scanf("%d", &nB);
    printf("Enter the elements for setB:\n");

    for (int i = 0; i < nB; i++) {
        scanf("%d", &value);
        add(setB, value);
    }
    displaySet(setB);
    do
    {
     case 1: struct Set* unionSet = unionSets(setA, setB);
    	    printf("Union of A and B: ");
        	displaySet(unionSet);
    	    break;
     case 2:struct Set* intersectionSet = intersectionSets(setA, setB);
    	  printf("Intersection of A and B: ");
          displaySet(intersectionSet);
          break;
     case 3: str break;
            default:
                printf("Wrong choice\n");
        }
    } while (choice != 5);
uct Set* differenceA = differenceA(setA, setB);
          printf("Difference of A - B: ");
          displaySet(differenceA);
          break;

    case 4: struct Set* differenceB = differenceB(setB, setA);
           printf("Difference of B - A: ");
           displaySet(differenceB);
          break;
    case 5:exit(0);
           break;
     default:
                printf("Wrong choice\n");
        }
    } while (choice != 5);


    freeSet(setA);
    freeSet(setB);
    freeSet(unionSet);
    freeSet(intersectionSet);
    freeSet(differenceA);
    freeSet(differenceB);
    


    return 0;
}
