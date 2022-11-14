#include <stdio.h>

int main(void)
{
    int numberOne, numberTwo, GCD;

    printf("\nEnter Number One: ");
    scanf("%d", &numberOne);

    printf("\nEnter Number Two: ");
    scanf("%d", &numberTwo);

    for (int i = 1; i <= numberOne && i <= numberTwo; i++)
    {
        if (numberOne % i == 0 && numberTwo % i == 0)
        {
            GCD = i;
        }
    }

    printf("\n\nGCD of %d and %d is %d", numberOne, numberTwo, GCD);

    return 0;
}