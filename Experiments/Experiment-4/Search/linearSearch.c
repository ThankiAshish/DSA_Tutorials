#include <stdio.h>
#include <stdlib.h>

int linearSearch(int array[], int size, int element) {
  for (int i = 0; i < size; i++) {
    if (array[i] == element)
      return i;
  }
  return -1;
}

int main(void) {
  int array[10] = {5, 6, 7, 10, 15, 25, 56, 67, 89, 90};
  int size = 10;

  int element;
  printf("\nEnter Element You Want To Search: ");
  scanf("%d", &element);

  int index = linearSearch(array, size, element);
  (index == -1) ? printf("\nElement Not Found!\n")
                : printf("\nElement Found at Position %d!\n", index);

  return 0;
}