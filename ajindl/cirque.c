#include <stdio.h>
#include <stdlib.h>

int MAX; 

struct CircularQueue {
    int *items; 
    int front;
    int rear;
};

struct CircularQueue* createQueue(int size) {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->items = (int*)malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}


int isFull(struct CircularQueue* queue) {
    return (queue->front == (queue->rear + 1) % MAX);
}

int isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1);
}

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

int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; 
    }
    int item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
    return item;
}

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

int main() {
    int choice, value, element;

    
    printf("Enter the size of the queue: ");
    scanf("%d", &MAX);
    struct CircularQueue* queue = createQueue(MAX);

    do {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display Queue");
        printf("\n4. Search for an Element");
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
            case 4:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                search(queue, element);
                break;
            case 5:
                free(queue->items);
                free(queue);         
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Wrong choice\n");
        }
    } while (choice != 5);

    return 0;
}
