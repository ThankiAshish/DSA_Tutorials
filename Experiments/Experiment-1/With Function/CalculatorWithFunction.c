#include <stdio.h>
#include <stdlib.h>

void calculator(int operandOne, int operandTwo, char operation)
{
    switch (operation)
    {
    case '+':
        printf("\nAddition: %d\n", operandOne + operandTwo);
        break;

    case '-':
        printf("\nSubstraction: %d\n", operandOne - operandTwo);
        break;

    case '*':
        printf("\nMultiplication: %d\n", operandOne * operandTwo);
        break;

    case '/':
        printf("\nDivision: %d\n", operandOne / operandTwo);
        break;

    default:
        exit(0);
    }
}

int main(void)
{
    int operandOne, operandTwo;
    char operation;

    printf("\nEnter Operand One: ");
    scanf("%d", &operandOne);

    printf("\nEnter Operation Sign: ");
    scanf(" %c", &operation);

    printf("\nEnter Operand Two: ");
    scanf("%d", &operandTwo);

    calculator(operandOne, operandTwo, operation);

    return 0;
}