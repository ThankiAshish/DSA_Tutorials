#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int top = -1, size;
int stack[MAX];

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

void push()
{
    if (top >= size)
    {
        printf("\nStack Overflow!");
        return;
    }
    int elem;
    printf("\nEnter Element: ");
    scanf("%d", &elem);
    stack[++top] = elem;
    printf("\n%d Inserted!", stack[top]);
    return;
}

void pop()
{
    if (top < 0)
    {
        printf("\nStack Underflow!");
        return;
    }
    printf("\n%d Removed!", stack[top]);
    stack[--top];
    return;
}

void peep()
{
    if (top < 0)
    {
        printf("\nStack Underflow!");
        return;
    }
    printf("\nTop Element: %d", stack[top]);
    return;
}

void display()
{
    if (top < 0)
    {
        printf("\nStack Underflow!");
        return;
    }
    printf("\n");
    for (int i = top; i >= 0; i--)
        printf("Stack[%d]: %d\n", i, stack[i]);
    return;
}

void change()
{
    int index, changedElem;
    printf("\nEnter the Index You Want to Change (From 1 to %d): ", size);
    scanf("%d", &index);
    index -= 1;
    if (index >= 0 && index < size && index <= top)
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
    return;
}

int main(void)
{
    int choice;
    printf("Enter Stack Size (MAX 100): ");
    scanf("%d", &size);

    while (1)
    {
        menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peep();
            break;

        case 4:
            display();
            break;

        case 5:
            change();
            break;

        case 6:
            exit(-1);

        default:
            printf("\nInvalid Choice!");
        }
    }
    return 0;
}