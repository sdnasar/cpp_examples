#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num, *arr, i;
  num = 4;
  arr = (int *)malloc(num * sizeof(int));
  for (i = 0; i < num; i++) {
    arr[i] = i;
  }

  for (i = 0; i < num / 2; i++) {
    *(arr + i) ^= *(arr + ((num - 1) - i));
    *(arr + ((num - 1) - i)) ^= *(arr + i);
    *(arr + i) ^= *(arr + ((num - 1) - i));
  }

  for (i = 0; i < num; i++) printf("%d ", *(arr + i));
  printf("\n");
  return 0;
}
