#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front;
    int rear;
    int capacity;
    int *array;
} typedef Queue;

Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));

    if (!queue)
        return NULL;

    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));

    if (!queue->array)
        return NULL;

    return queue;
}

int isFull(Queue *queue)
{
    return ((queue->front == queue->rear + 1) ||
            (queue->front == 0 && queue->rear == queue->capacity - 1));
}

int isEmpty(Queue *queue) { return queue->rear == -1; }

int frontElement(Queue *queue)
{
    if (!isEmpty(queue))
        return queue->array[queue->front];

    return 0;
}

void display(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("\nQueue Underflow!\n");
        return;
    }

    int i;
    printf("\n Front Pointer -> %d ", queue->front);
    printf("\n Queue -> ");
    for (i = queue->front; i != queue->rear; i++)
    {
        printf("%d ", queue->array[i]);
    }
    printf("%d ", queue->array[i]);
    printf("\n Rear Pointer -> %d \n", queue->rear);
    return;
}

void enqueue(Queue *queue, int element)
{
    queue->array[++queue->rear] = element;
    if (queue->front == -1)
        queue->front = 0;
    return;
}

int dequeue(Queue *queue)
{
    int data = queue->array[queue->front];
    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front += 1;
    }
    return data;
}

void menu()
{
    printf("\nSelect a Choice From Below: ");
    printf("\n\t1. Enqueue");
    printf("\n\t2. Dequeue");
    printf("\n\t3. Top Element");
    printf("\n\t4. Display");
    printf("\n\t5. Exit");
    printf("\n\nEnter Your Choice: ");
    return;
}

int main(void)
{
    int capacity;
    printf("Enter Size of Queue: ");
    scanf("%d", &capacity);

    if (capacity <= 0)
    {
        printf("\nCannot Give Size %d to a Queue!\n", capacity);
        exit(-1);
    }

    Queue *queue = createQueue(capacity);

    while (1)
    {
        int choice, element;
        menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (isFull(queue))
            {
                printf("\nQueue Overflow!\n");
                break;
            }
            printf("\nEnter Element: ");
            scanf("%d", &element);
            enqueue(queue, element);
            printf("\n%d Enqueued!\n", element);
            break;
        case 2:
            if (isEmpty(queue))
            {
                printf("\nQueue Underflow!\n");
                break;
            }
            printf("\n%d Dequeued!\n", dequeue(queue));
            break;
        case 3:
            if (isEmpty(queue))
            {
                printf("\nQueue Underflow!\n");
                break;
            }
            printf("\nFront Element: %d\n", frontElement(queue));
            break;
        case 4:
            display(queue);
            break;
        case 5:
            exit(0);
        default:
            printf("\n\nInvalid Choice!");
            break;
        }
    }

    return 0;
}