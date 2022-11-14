#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int *array;
} typedef Stack;

int main(void)
{
    int size = 0, choice, elem, changedElem, index;

    do
    {
        printf("\nEnter Size Of Stack: ");
        scanf("%d", &size);
        if (size <= 0)
        {
            printf("\n0 or Negative Value Not Allowed!");
        }
    } while (!(size > 0));

    Stack *stack = malloc(sizeof(Stack));

    if (!stack)
    {
        printf("\nFailed Allocating Memory to Stack!");
        exit(-1);
    }

    stack->size = size;
    stack->top = -1;
    stack->array = malloc(stack->size * sizeof(int));

    if (!stack->array)
    {
        printf("\nFailed Allocating Memory to Array!");
        exit(-1);
    }

    do
    {
        printf("\n\nPick Your Choice: ");
        printf("\n\t1. Push");
        printf("\n\t2. Pop");
        printf("\n\t3. Peep");
        printf("\n\t4. Display");
        printf("\n\t5. Change");
        printf("\n\t6. Exit");
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (stack->top == stack->size - 1)
            {
                printf("\nStack Overflow!");
                break;
            }
            printf("\nEnter Element: ");
            scanf("%d", &elem);
            stack->array[++stack->top] = elem;
            printf("\n%d Inserted!", stack->array[stack->top]);
            break;

        case 2:
            if (stack->top == -1)
            {
                printf("\nStack Underflow!");
                break;
            }
            printf("\n%d Deleted!", stack->array[stack->top--]);
            break;

        case 3:
            if (stack->top == -1)
            {
                printf("\nStack Underflow!");
                break;
            }
            printf("\nTop Element: %d", stack->array[stack->top]);
            break;

        case 4:
            if (stack->top == -1)
            {
                printf("\nStack Underflow!");
                break;
            }
            for (int i = stack->top; i >= 0; i--)
            {
                printf("\nStack[%d]: %d", i, stack->array[i]);
            }
            break;

        case 5:
            if (stack->top == -1)
            {
                printf("\nStack Underflow!");
                break;
            }
            printf("\nEnter The Index of The Element You Want to Change (From 1 to %d): ", (stack->top) + 1);
            scanf("%d", &index);
            index -= 1;
            if (index > stack->top || index < 0)
            {
                printf("\nInvalid Index!");
                break;
            }
            printf("\nEnter Element: ");
            scanf("%d", &changedElem);
            printf("\n%d Changed to %d", stack->array[index], changedElem);
            stack->array[index] = changedElem;
            break;

        case 6:
            exit(0);

        default:
            printf("\nInvalid Choice!");
        }
    } while (choice != 6);

    return 0;
}