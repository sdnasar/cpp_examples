#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);
  int *arr = (int *)malloc(n * sizeof(int));
  int len = 0;
  while (len < n) {
    scanf("%d", arr + len);
    ++len;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  printf("%d\n", sum);
  return 0;
}
