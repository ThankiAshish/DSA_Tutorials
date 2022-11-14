#include <stdio.h>

int main(void) {
  int operandOne, operandTwo;
  char operation;

  printf("\nEnter Operand One: ");
  scanf("%d",&operandOne);

  printf("\nEnter Operation Sign: ");
  scanf(" %c",&operation);

  printf("\nEnter Operand Two: ");
  scanf("%d",&operandTwo);

  switch(operation) {
    case '+':;
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
  
  return 0;
}