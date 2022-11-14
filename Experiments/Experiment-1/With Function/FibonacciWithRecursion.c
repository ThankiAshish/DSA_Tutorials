#include <stdio.h>
#include <stdlib.h>

int fibonacci(int number)
{
    if (number == 0 || number == 1)
    {
        return number;
    }
    return (fibonacci(number - 1) + fibonacci(number - 2));
}

int main(void)
{
    int number;

    printf("\nEnter a Positive Number: ");
    scanf("%d", &number);

    printf("\nFibonacci Sequence till %d: \n\n", number);

    printf("0 ");

    for (int i = 1; i < number; i++)
    {
        printf("%d ", fibonacci(i));
    }

    printf("\n");
    return 0;
}