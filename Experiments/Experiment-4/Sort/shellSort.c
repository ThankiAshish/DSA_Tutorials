#include <math.h>
#include <stdio.h>

void shellSort(int array[], int size) {
  for (int interval = floor(size / 2); interval > 0; interval /= 2) {
    for (int iteration = interval; iteration < size; iteration++) {
      int temp = array[iteration];
      int j;
      for (j = iteration; j >= interval && array[j - interval] > temp;
           j -= interval) {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
  return;
}

int main(void) {
  int array[9] = {11, 55, 22, 6, 78, 89, 55, 77, 34};
  int size = 9;

  printf("\nSorting Your Array.......\n\n");
  shellSort(array, size);
  for (int i = 0; i < size; i++)
    printf("Array[%d]: %d\n", i, array[i]);
  return 0;
}