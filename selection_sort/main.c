#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
  int arr[10] = {4, 2, 6, 10, 4, 7, 8, 9, 10, 2};
  int size = sizeof(arr) / sizeof(arr[0]);

  printArray(arr, size);
  sort(arr, size);
  printf("\n");
  printArray(arr, size);

  return 0;
}