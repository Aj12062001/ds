#include <stdio.h>
#include <stdlib.h>

int MAX; // size of the queue

struct CircularQueue {
    int *items; // dynamically allocated array for the queue items
    int front;
    int rear;
};

// Function to create a circular queue
struct CircularQueue* createQueue(int size) {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->items = (int*)malloc(size * sizeof(int)); // dynamically allocate array
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
int isFull(struct CircularQueue* queue) {
    return (queue->front == (queue->rear + 1) % MAX);
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1);
}

// Function to add an item to the queue
void enqueue(struct CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->items[queue->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an item from the queue
int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; // Indicate queue is empty
    }
    int item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        // Queue is now empty
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
    return item;
}

// Function to display the queue
void displayQueue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i = queue->front;
    while (1) {
        printf("%d ", queue->items[i]);
        if (i == queue->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}
void search(struct CircularQueue* queue, int element) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    int i = queue->front;
    while (1) {
        if (queue->items[i] == element) {
            printf("Element %d found at position %d\n", element, i);
            return;
        }
        if (i == queue->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("Element %d not found in the queue\n", element);
}

// Main function to demonstrate circular queue operations
int main() {
    int choice, value,element;

    // Ask for queue size
    printf("Enter the size of the queue: ");
    scanf("%d", &MAX);

    // Create queue with dynamic size
    struct CircularQueue* queue = createQueue(MAX);

    do {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display Queue");
        printf("\n4. search");
	printf("\n5. Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Input the element for insertion in queue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                displayQueue(queue);
                break;
	    case 4:printf("enter the element to be search: \n");
		   scanf("%d",&element);
		   search(queue,element);
		  break;
            case 5:
                free(queue->items); // Free dynamically allocated memory for items
                free(queue);         // Free the queue structure itself
                exit(0);
                break;
            default:
                printf("Wrong choice\n");
        }
    } while (choice != 4);

    return 0;
}

