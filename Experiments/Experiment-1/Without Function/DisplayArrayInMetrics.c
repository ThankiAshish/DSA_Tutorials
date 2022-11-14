#include <stdio.h>
#define MAX 100

int main(void)
{
    int array[MAX], size;

    printf("Enter Size of Array (MAX 100): ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter Array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    printf("\nThe Array You Entered: \n");

    for (int i = 0; i < size; i++)
    {
        printf("Array[%d]: %d\n", i, array[i]);
    }

    return 0;
}