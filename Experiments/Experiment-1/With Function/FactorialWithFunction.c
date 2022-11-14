#include <stdio.h>
#include <stdlib.h>

int factorial(int number)
{
    if (number < 0)
    {
        printf("\nFactorial Not Possible for Negative Numbers!\n\n");
        exit(-1);
    }

    if (number == 0 || number == 1)
    {
        return number;
    }

    return number * factorial(number - 1);
}

int main()
{
    int number;
    printf("\nEnter A Number: ");
    scanf("%d", &number);

    printf("\nFactorial of %d: %d\n\n", number, factorial(number));
    return 0;
}