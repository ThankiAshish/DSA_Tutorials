#include <stdio.h>

void insertionSort(int array[], int size) {
  for (int i = 1; i < size; i++) {
    int key = array[i];
    int j;
    for (j = i - 1; key < array[j] && j >= 0; j--) {
      array[j + 1] = array[j];
    }
    array[j + 1] = key;
  }
  return;
}

int main(void) {
  int array[9] = {11, 55, 22, 6, 78, 89, 55, 77, 34};
  int size = 9;
  printf("\nSorting Your Array.......\n\n");
  insertionSort(array, size);
  for (int i = 0; i < size; i++)
    printf("Array[%d]: %d\n", i, array[i]);
  return 0;
}