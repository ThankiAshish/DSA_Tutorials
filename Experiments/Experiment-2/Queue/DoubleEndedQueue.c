#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front;
    int rear;
    int *array;
    int capacity;
    int occupiedBlocks;
} typedef Queue;

void inputRestMenu()
{
    printf("\nSelect a Choice From Below: ");
    printf("\n\n1. Enqueue at Rear");
    printf("\n2. Dequeue at Front");
    printf("\n3. Dequeue at Rear");
    printf("\n4. Display");
    printf("\n5. Exit");
    printf("\n\nEnter Your Choice: ");
    return;
}

void outputRestMenu()
{
    printf("\nSelect a Choice From Below: ");
    printf("\n\n1. Enqueue at Rear");
    printf("\n2. Enqueue at Front");
    printf("\n3. Dequeue at Front");
    printf("\n4. Display");
    printf("\n5. Exit");
    printf("\n\nEnter Your Choice: ");
    return;
}

Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (!queue)
        return NULL;
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->occupiedBlocks = 0;
    queue->array = (int *)calloc(queue->capacity, sizeof(int));
    if (!queue->array)
        return NULL;
    return queue;
}

int isFull(Queue *queue) { return queue->occupiedBlocks == queue->capacity; }

int isEmpty(Queue *queue) { return queue->occupiedBlocks == 0; }

void enqueueFront(Queue *queue)
{
    if (isFull(queue))
    {
        printf("\nQueue Overflow!\n");
        return;
    }

    int elem;
    printf("\nEnter Element: ");
    scanf("%d", &elem);

    if (queue->front == -1)
    {
        queue->front = queue->rear = 0;
    }
    else
    {
        if (queue->front == 0)
        {
            queue->front = queue->capacity - 1;
        }
        else
        {
            queue->front -= 1;
        }
    }

    queue->array[queue->front] = elem;
    queue->occupiedBlocks += 1;
    return;
}

void dequeueRear(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("\nQueue Underflow!\n");
        return;
    }

    printf("\n%d Dequeued!\n", queue->array[queue->rear]);

    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        if (queue->rear == 0)
        {
            queue->rear = queue->capacity - 1;
        }
        else
        {
            queue->rear -= 1;
        }
    }
    queue->occupiedBlocks -= 1;
    return;
}

void enqueueRear(Queue *queue)
{
    if (isFull(queue))
    {
        printf("\nQueue Overflow!\n");
        return;
    }

    int elem;
    printf("\nEnter Element: ");
    scanf("%d", &elem);

    if (queue->front == -1)
    {
        queue->front = queue->rear = 0;
    }
    else
    {
        if (queue->rear == queue->capacity - 1)
        {
            queue->rear = 0;
        }
        else
        {
            queue->rear += 1;
        }
    }

    queue->array[queue->rear] = elem;
    printf("\n%d Enqueued!\n", elem);
    queue->occupiedBlocks += 1;
    return;
}

void dequeueFront(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("\nQueue Underflow!\n");
        return;
    }

    printf("\n%d Dequeued!\n", queue->array[queue->front]);

    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        if (queue->front == queue->capacity - 1)
        {
            queue->front = 0;
        }
        else
        {
            queue->front += 1;
        }
    }
    queue->occupiedBlocks -= 1;
    return;
}

void display(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("\nQueue Underflow!\n");
        return;
    }

    int front = queue->front;
    int rear = queue->rear;

    if (front <= rear)
    {
        while (front <= rear)
        {
            printf(" %d ", queue->array[front]);
            front++;
        }
    }
    else
    {
        while (front <= queue->capacity - 1)
        {
            printf(" %d ", queue->array[front]);
            front++;
        }
        front = 0;
        while (front <= rear)
        {
            printf(" %d ", queue->array[front]);
            front++;
        }
    }
    printf("\n");

    return;
}

void inputRestrictedQueue(Queue *queue)
{
    int choice;
    while (1)
    {
        inputRestMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueueRear(queue);
            break;
        case 2:
            dequeueFront(queue);
            break;
        case 3:
            dequeueRear(queue);
            break;
        case 4:
            display(queue);
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid Choice!\n");
            exit(-1);
        }
    }
    return;
}

void outputRestrictedQueue(Queue *queue)
{
    int choice;
    while (1)
    {
        outputRestMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueueRear(queue);
            break;
        case 2:
            enqueueFront(queue);
            break;
        case 3:
            dequeueFront(queue);
            break;
        case 4:
            display(queue);
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid Choice!\n");
            exit(-1);
        }
    }
    return;
}

int main(void)
{
    int size, choice;

    printf("Select Your Choice: \n\n");
    printf("1. Input Restricted Queue\n");
    printf("2. Output Restricted Queue\n");
    printf("3. Exit\n\n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);

    do
    {
        printf("\nEnter Queue Size: ");
        scanf("%d", &size);
        if (size <= 0)
            printf("\nSize Cannot be %d\n", size);
    } while (!(size > 0));

    Queue *queue = createQueue(size);

    switch (choice)
    {
    case 1:
        inputRestrictedQueue(queue);
        break;
    case 2:
        outputRestrictedQueue(queue);
        break;
    case 3:
        exit(0);
    default:
        printf("\nInvalid Choice!\n");
        exit(-1);
    }
    return 0;
}