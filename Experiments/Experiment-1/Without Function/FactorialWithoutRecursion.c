#include <stdio.h>

int main(void)
{
    int number;
    unsigned long long fact = 1;

    printf("Enter A Positive Number: ");
    scanf("%d", &number);

    if (number < 0)
    {
        printf("\nFactorial Of 0 Doesn't Exist!");
    }
    else
    {
        for (int i = 1; i <= number; i++)
        {
            fact *= i;
        }
    }

    printf("\nFactorial of %d: %llu", number, fact);

    return 0;
}