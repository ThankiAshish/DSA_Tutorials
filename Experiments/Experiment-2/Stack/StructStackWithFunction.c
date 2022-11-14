#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int *array;
} typedef Stack;

void menu()
{
    printf("\n\nPick Your Choice: ");
    printf("\n\t1. Push");
    printf("\n\t2. Pop");
    printf("\n\t3. Peep");
    printf("\n\t4. Display");
    printf("\n\t5. Change");
    printf("\n\t6. Exit");
    printf("\n\nEnter Your Choice: ");
}

int enterData()
{
    int data;
    printf("\nEnter Element: ");
    scanf("%d", &data);
    return data;
}

Stack *createStack(int size)
{
    Stack *S = malloc(sizeof(Stack));

    if (!S)
        return NULL;

    S->size = size;
    S->top = -1;
    S->array = malloc(S->size * sizeof(int));

    if (!S->array)
        return NULL;
    return S;
}

int isFull(Stack *S)
{
    return (S->top == S->size - 1);
}

int isEmpty(Stack *S)
{
    return S->top == -1;
}

void push(Stack *S, int data)
{
    S->array[++S->top] = data;
    printf("\n%d Inserted!", S->array[S->top]);
    return;
}

int pop(Stack *S)
{
    return S->array[S->top--];
}

int peep(Stack *S)
{
    return S->array[S->top];
}

void display(Stack *S)
{
    for (int i = S->top; i >= 0; i--)
    {
        printf("\nStack[%d]: %d", i, S->array[i]);
    }
    return;
}

void change(Stack *S)
{
    int index, changedElem;
    printf("\nEnter Index From 1 to %d: ", (S->top) + 1);
    scanf("%d", &index);
    index -= 1;

    if (index > S->top)
    {
        printf("\nInvalid Index!");
        return;
    }

    printf("\nEnter Element: ");
    scanf("%d", &changedElem);
    printf("\nElement Changed From %d to %d!", S->array[index], changedElem);
    S->array[index] = changedElem;
    return;
}

int main(void)
{
    int size = 0, choice;
    do
    {
        printf("\nEnter Size of Stack: ");
        scanf("%d", &size);
        if (size <= 0)
        {
            printf("\n0 or Negative Size Not Allowed!\n");
        }
    } while (!(size > 0));

    Stack *stack = createStack(size);

    while (1)
    {
        menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (isFull(stack))
            {
                printf("\nStack Overflow!");
                break;
            }
            push(stack, enterData());
            break;

        case 2:
            if (isEmpty(stack))
            {
                printf("\nStack Underflow!");
                break;
            }
            printf("\n%d Deleted!", pop(stack));
            break;

        case 3:
            if (isEmpty(stack))
            {
                printf("\nStack Underflow!");
                break;
            }
            printf("\nTop Element: %d", peep(stack));
            break;

        case 4:
            if (isEmpty(stack))
            {
                printf("\nStack Underflow!");
                break;
            }
            display(stack);
            break;

        case 5:
            if (isEmpty(stack))
            {
                printf("\nStack Underflow!");
                break;
            }
            change(stack);
            break;

        case 6:
            exit(-1);

        default:
            printf("\nInvalid Choice!");
        }
    }
    return 0;
}