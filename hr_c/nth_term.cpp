#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Complete the following function.

int find_nth_term(int n, int a, int b, int c) {
  int i = 4;
  int sum = a + b + c;
  if (++i <= n) {
    sum = find_nth_term(n - 1, b, c, sum);
  }
  return sum;
}

int main() {
  int n, a, b, c;

  scanf("%d %d %d %d", &n, &a, &b, &c);
  int ans = find_nth_term(n, a, b, c);

  printf("%d", ans);
  return 0;
}