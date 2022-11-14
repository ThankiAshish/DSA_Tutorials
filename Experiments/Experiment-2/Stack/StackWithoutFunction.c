#include <stdio.h>
#include <stdlib.h>
#define MAX 100

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

int main(void)
{
    int top = -1, size, choice;
    int index, changedElem;
    int stack[MAX];

    printf("Enter Array Size (MAX 100): ");
    scanf("%d", &size);

    while (1)
    {
        menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (top < size - 1)
            {
                int elem;
                printf("\nEnter Element: ");
                scanf("%d", &elem);
                stack[++top] = elem;
                printf("\n%d Inserted!", stack[top]);
            }
            else
            {
                printf("\nStack Overflow!");
            }
            break;

        case 2:
            if (top < 0)
            {
                printf("\nStack Underflow!");
                break;
            }
            printf("\n%d Removed!", stack[top]);
            stack[--top];
            break;

        case 3:
            if (top < 0)
            {
                printf("\nStack Underflow!");
                break;
            }
            printf("\nTop Element: %d", stack[top]);
            break;

        case 4:
            if (top < 0)
            {
                printf("\nStack Underflow!");
                break;
            }
            printf("\n");
            for (int i = top; i >= 0; i--)
            {
                printf("Stack[%d]: %d\n", i, stack[i]);
            }
            break;

        case 5:
            printf("\nEnter the Index You Want to Change (From 1 to %d): ", size);
            scanf("%d", &index);
            index -= 1;
            if (index >= 0 && index < size)
            {
                printf("\nEnter the Element: ");
                scanf("%d", &changedElem);
                printf("\n%d Changed to %d", stack[index], changedElem);
                stack[index] = changedElem;
            }
            else
            {
                printf("\nInvalid Index");
            }
            break;

        case 6:
            exit(0);

        default:
            printf("\nInvalid Choice!");
        }
    }
    return 0;
}