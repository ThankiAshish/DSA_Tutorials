#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int capacity;
    int top;
    int *array;
} typedef Stack;

Stack *createStack(int capacity)
{
    Stack *S = (Stack *)malloc(sizeof(Stack));
    if (!S)
        return NULL;

    S->capacity = capacity;
    S->top = -1;
    S->array = (int *)malloc(S->capacity * sizeof(int));

    return S;
}

int isFull(Stack *stack) { return (stack->top) == (stack->capacity - 1); }

int isEmpty(Stack *stack) { return stack->top == -1; }

void push(Stack *stack, int element)
{
    if (isFull(stack))
        return;

    stack->array[++stack->top] = element;
    return;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
        return 0;
    return stack->array[stack->top--];
}

void moveDisks(char fromPole, char toPole, int disk)
{
    printf("\nMove Disk %d From \'%c\' to \'%c\'", disk, fromPole, toPole);
    return;
}

void handleMovementOfDisks(Stack *sourcePole, Stack *destinationPole,
                           char source, char destination)
{
    int diskOfSourcePole = pop(sourcePole);
    int diskOfDestinationPole = pop(destinationPole);

    if (!diskOfSourcePole)
    {
        push(sourcePole, diskOfDestinationPole);
        moveDisks(destination, source, diskOfDestinationPole);
    }
    else if (!diskOfDestinationPole)
    {
        push(destinationPole, diskOfSourcePole);
        moveDisks(source, destination, diskOfSourcePole);
    }
    else if (diskOfSourcePole > diskOfDestinationPole)
    {
        push(sourcePole, diskOfSourcePole);
        push(sourcePole, diskOfDestinationPole);
        moveDisks(destination, source, diskOfDestinationPole);
    }
    else
    {
        push(destinationPole, diskOfDestinationPole);
        push(destinationPole, diskOfSourcePole);
        moveDisks(source, destination, diskOfSourcePole);
    }
    return;
}

void towerOfHanoi(unsigned int numberOfDisks, Stack *source, Stack *destination,
                  Stack *auxiliary)
{
    int i, numberOfMoves;
    char sourcePole = 'S';
    char destinationPole = 'D';
    char auxiliaryPole = 'A';

    if (numberOfDisks % 2 == 0)
    {
        char temp = destinationPole;
        destinationPole = auxiliaryPole;
        auxiliaryPole = temp;
    }

    numberOfMoves = pow(2, numberOfDisks) - 1;

    for (i = numberOfDisks; i >= 1; i--)
        push(source, i);

    for (i = 1; i <= numberOfMoves; i++)
    {
        if (i % 3 == 1)
            handleMovementOfDisks(source, destination, sourcePole, destinationPole);
        if (i % 3 == 2)
            handleMovementOfDisks(source, auxiliary, sourcePole, auxiliaryPole);
        if (i % 3 == 0)
            handleMovementOfDisks(auxiliary, destination, auxiliaryPole,
                                  destinationPole);
    }
    return;
}

int main(void)
{
    unsigned int numberOfDisks = 2;
    printf("Enter Number of Disk (Min: 2): ");
    scanf("%u", &numberOfDisks);

    if (numberOfDisks < 2)
    {
        printf("\n\nMinimum 2 Disks Required!");
        exit(-1);
    }

    Stack *source, *destination, *auxiliary;

    source = createStack(numberOfDisks);
    destination = createStack(numberOfDisks);
    auxiliary = createStack(numberOfDisks);

    towerOfHanoi(numberOfDisks, source, destination, auxiliary);

    return 0;
}