#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
print occurrences of digits 0 - 9 in by space seperated
*/
int main() {
  int *a = (int *)malloc(10 * sizeof(int));
  for (int i = 0; i < 10; i++) {
    *(a + i) = 0;
  }
  char *s = (char *)malloc(1024 * sizeof(char));
  scanf("%s", s);
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      a[s[i] - '0'] += 1;
    }
  }

  for (int i = 0; i < 10; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  if (s) {
    free(s);
    puts("freeing s");
    s = NULL;
  }
  if (a) {
    free(a);
    puts("freeing a");
    a = NULL;
  }

  return 0;
}
