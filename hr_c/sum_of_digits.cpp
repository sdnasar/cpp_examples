#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", n);
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n = n / 10;
  }
  printf("%d\n", sum);
  return 0;
}