#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int num, *arr, i;
  scanf("%d", &num);
  arr = (int *)malloc(num * sizeof(int));
  for (i = 0; i < num; i++) {
    scanf("%d", arr + i);
  }
  int *arr_copy = (int *)malloc(num * sizeof(int));
  int j = 0;
  for (int i = num - 1; i >= 0; i--) {
    arr_copy[j++] = arr[i];
  }
  arr = arr_copy;
  for (i = 0; i < num; i++) printf("%d ", *(arr + i));
  printf("\n");
  for (i = 0; i < num; i++) printf("%d ", *(arr_copy + i));
  return 0;
}
