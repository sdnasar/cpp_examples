#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *s;
  s = (char *)malloc(1024 * sizeof(char));
  scanf("%[^\n]", s);
  s = (char *)realloc(s, strlen(s) + 1);
  char *p = strtok(s, " ");
  while (p) {
    printf("%s\n", p);
    p = strtok(NULL, " ");
  }

  return 0;
}
