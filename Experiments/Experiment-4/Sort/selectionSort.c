#include <stdio.h>

void swap(int *elemOne, int *elemTwo) {
  int temp = *elemOne;
  *elemOne = *elemTwo;
  *elemTwo = temp;
  return;
}

void selectionSort(int array[], int size) {
  int min;
  for (int i = 0; i < size - 1; i++) {
    min = i;
    for (int j = i + 1; j < size; j++) {
      if (array[j] < array[min])
        min = j;
    }
    swap(&array[min], &array[i]);
  }
  return;
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("Array[%d]: %d\n", i, array[i]);
  }
  return;
}

int main(void) {
  int array[9] = {12, 54, 23, 6, 78, 89, 5, 7, 34};
  int size = 9;

  printf("\nSorting Your Array.......\n\n");
  selectionSort(array, size);
  printArray(array, size);
  return 0;
}