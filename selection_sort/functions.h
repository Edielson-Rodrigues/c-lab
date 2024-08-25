#include <stdlib.h>
#include <stdio.h>

void sort(int arr[], int size);
void printArray(int arr[], int size);

void sort(int arr[], int size) {
  int current, indexChange;

  for (int i = 0; i < size; i++) {
    current = arr[i];
    indexChange = -1;

    for (int j = i; j < size; j++) {
      if (current > arr[j]) {
        if (indexChange == -1) {
          indexChange = j;
        } else if (arr[indexChange] > arr[j]) {
          indexChange = j;
        }
      }
    }

    if (indexChange != -1) {
      int aux = current;
      arr[i] = arr[indexChange];
      arr[indexChange] = aux;
    }
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}