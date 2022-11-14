#include <stdio.h>
#define MAX 5

int main(void)
{
    int array[MAX];

    for (int i = 0; i < MAX; i++)
    {
        printf("\nEnter Array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    int min = array[0], max = array[0];

    for (int i = 1; i < MAX; i++)
    {
        if (min > array[i])
            min = array[i];
        if (max < array[i])
            max = array[i];
    }

    printf("\n\nMax: %d, Min: %d", max, min);

    return 0;
}