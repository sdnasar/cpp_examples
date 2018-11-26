#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a, b) a < b ? a : b
/*
n = 3
3 3 3 3 3
3 2 2 2 3
3 2 1 2 3
3 2 2 2 3
3 3 3 3 3
 */
int main() {
  int n;
  scanf("%d", &n);
  int loop = n * 2 - 1;
  int subraction_value;
  for (int r = 0; r < loop; r++) {
    for (int c = 0; c < loop; c++) {
      if (r + c >= loop) {
        subraction_value = ((loop - (r + c)) + (min(r, c))) - 1;
      } else {
        subraction_value = min(r, c);
      }
      printf("%d ", n - subraction_value);
    }
    printf("\n");
  }
  return 0;
}
