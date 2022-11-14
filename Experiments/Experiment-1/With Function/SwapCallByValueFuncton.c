#include <stdio.h>

void swap(int numberOne, int numberTwo) {
  int temp;

  printf("\n\nBefore Swapping: ");
  printf("\n\tNumberOne: %d, NumberTwo: %d", numberOne, numberTwo);
  
  temp = numberOne;
  numberOne = numberTwo;
  numberTwo = temp;

  printf("\n\nAfter Swapping: ");
  printf("\n\tNumberOne: %d, NumberTwo: %d\n", numberOne, numberTwo);
}

int main(void) {
  int numberOne, numberTwo;

  printf("\nEnter Number One: ");
  scanf("%d", &numberOne);

  printf("\nEnter Number Two: ");
  scanf("%d", &numberTwo);

  swap(numberOne, numberTwo);
  
  return 0;
}