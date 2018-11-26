#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculate_the_maximum(int n, int k) {
  int max_and = 0;
  int max_or = 0;
  int max_xor = 0;
  int temp = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      // bitwise and
      temp = i & j;
      if (temp >= max_and && temp < k) max_and = temp;
      // bitwise or
      temp = i | j;
      if (temp >= max_or && temp < k) max_or = temp;
      // bitwise xor
      temp = i ^ j;
      if (temp >= max_xor && temp < k) max_xor = temp;
    }
  }
  printf("%d\n%d\n%d\n", max_and, max_or, max_xor);
}

int main() {
  int n, k;

  scanf("%d %d", &n, &k);
  calculate_the_maximum(n, k);

  return 0;
}
