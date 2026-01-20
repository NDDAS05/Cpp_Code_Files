#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *init(int size) {
  int *arr = (int *)malloc(sizeof(int) * size);

  if (arr)
    return arr;

  else {
    printf("Error occured.\n");
    exit(1);
  }
}

int *fillArray(int *arr, int size) {
  if (arr) {
    for (int i = 0; i < size; i++) {
      int elem;
      scanf("%d", &elem);
      arr[i] = elem;
    }
  }
  return arr;
}

void freeArr(int *arr) {
  if (arr)
    free(arr);
  arr = NULL;
}

void printArr(int *arr, int size) {
  if (arr) {
    for (int i = 0; i < size; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
  }

  else
    printf("Invalid array.\n");
}

int maxElem(int *arr, int size) {
  if (arr) {
    int max = INT_MIN;

    for (int i = 0; i < size; i++) {
      if (arr[i] > max)
        max = arr[i];
    }
    return max;
  }

  else {
    printf("Invalid array. \nOperation could not be completed.\n");
    return 1;
  }
}

int minElem(int *arr, int size) {
  if (arr) {
    int min = INT_MAX;

    for (int i = 0; i < size; i++) {
      if (arr[i] < min)
        min = arr[i];
    }
    return min;
  }

  else {
    printf("Invalid array. \nOperation could not be completed.\n");
    return 1;
  }
}
