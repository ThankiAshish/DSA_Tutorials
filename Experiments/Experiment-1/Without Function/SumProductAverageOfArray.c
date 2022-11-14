#include <stdio.h>
#define MAX 100

int main(void)
{
    int array[MAX], size;
    int sum = 0, product = 1, average;

    printf("Enter Size of Array (MAX 100): ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter Array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < size; i++)
    {
        sum += array[i];
        product *= array[i];
    }

    average = sum / size;

    printf("\nSum: %d, Product: %d, Average: %d", sum, product, average);

    return 0;
}