#include <stdio.h>

void bubbleSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    for (int i = 0; i < size - step - 1; i++) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
  return;
}

int main(void) {
  int array[9] = {12, 54, 23, 6, 78, 89, 5, 7, 34};
  int size = 9;
  printf("\nSorting Your Array.......\n\n");
  bubbleSort(array, size);
  for (int i = 0; i < size; i++) {
    printf("Array[%d]: %d\n", i, array[i]);
  }
  return 0;
}