#include <stdio.h>

int GCD(int numberOne, int numberTwo)
{
    if (numberTwo != 0)
        return GCD(numberTwo, numberOne % numberTwo);
    else
        return numberOne;
}

int main(void)
{
    int numberOne, numberTwo;

    printf("\nEnter Number One: ");
    scanf("%d", &numberOne);

    printf("\nEnter Number Two: ");
    scanf("%d", &numberTwo);

    printf("\n\nGCD of %d and %d is %d\n", numberOne, numberTwo, GCD(numberOne, numberTwo));
    return 0;
}