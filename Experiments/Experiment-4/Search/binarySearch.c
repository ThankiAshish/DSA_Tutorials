#include <stdio.h>
#include <stdlib.h>

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

int binarySearch(int array[], int size, int element) {
  int lowerBound = 0;
  int upperBound = size - 1;

  while (lowerBound <= upperBound) {
    int midPoint = lowerBound + (upperBound - lowerBound) / 2;
    if (array[midPoint] == element)
      return midPoint;
    else if (array[midPoint] < element)
      lowerBound = midPoint + 1;
    else
      upperBound = midPoint - 1;
  }
  return -1;
}

int main(void) {
  int size = 10, element;
  int array[10] = {5, 6, 7, 10, 15, 25, 56, 67, 89, 90};

  printf("\nEnter Element You Want to Search: ");
  scanf("%d", &element);

  int index = binarySearch(array, size, element);
  (index == -1) ? printf("\nElement Not Found!")
                : printf("\nElement Found on Position %d!", index);

  return 0;
}