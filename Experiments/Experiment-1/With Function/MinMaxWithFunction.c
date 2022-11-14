#include <stdio.h>
#define MAX 5
int min, max;

void minMax(int array[])
{
    for (int i = 1; i < MAX; i++)
    {
        if (min > array[i])
            min = array[i];
        if (max < array[i])
            max = array[i];
    }
}

int main(void)
{
    int array[MAX];

    for (int i = 0; i < MAX; i++)
    {
        printf("\nEnter Array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    min = max = array[0];
    minMax(array);

    printf("\n\nMin: %d, Max: %d", min, max);

    return 0;
}