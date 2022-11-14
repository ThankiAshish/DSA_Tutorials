#include <stdio.h>
#define MAX 100

int main(void)
{
    int array[MAX], revereseArray[MAX], size;

    printf("Enter Size of Array (MAX 100): ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter Array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    for (int i = size - 1, j = 0; i >= 0; i--, j++)
    {
        revereseArray[j] = array[i];
    }

    printf("\nReveresed Array: \n\n");

    for (int i = 0; i < size; i++)
    {
        printf("Array[%d]: %d\n", i, revereseArray[i]);
    }
    return 0;
}