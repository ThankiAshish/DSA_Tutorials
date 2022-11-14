#include <stdio.h>

int main(void) {
  int numberOne, numberTwo;
  
  printf("\nEnter First Number: ");
  scanf("%d", &numberOne);

  printf("\nEnter Second Number: ");
  scanf("%d", &numberTwo);

  printf("\n\nBefore Swapping: ");
  printf("\n\n\tNumberOne: %d, NumberTwo: %d", numberOne, numberTwo);
  
  numberOne = numberOne + numberTwo;
  numberTwo = numberOne - numberTwo;
  numberOne = numberOne - numberTwo;

  printf("\n\nAfter Swapping: ");
  printf("\n\n\tNumberOne: %d, NumberTwo: %d\n", numberOne, numberTwo);
  
  return 0;
}