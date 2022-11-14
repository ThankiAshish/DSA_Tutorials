#include <stdio.h>

int main(void)
{
    int termOne, termTwo, nextTerm = 0, number;
    termOne = 0;
    termTwo = 1;

    printf("\nEnter a Positive Number: ");
    scanf("%d", &number);

    printf("First %d terms of Fibonacci series: \n", number);

    printf("0 ");
    nextTerm = 1;

    for (int i = 1; i < number; i++)
    {
        printf("%d ", nextTerm);
        nextTerm = termOne + termTwo;
        termOne = termTwo;
        termTwo = nextTerm;
    }
    return 0;
}