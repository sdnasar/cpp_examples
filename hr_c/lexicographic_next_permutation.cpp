#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline void print_array(char **arr, const int size) {
  for (int i = 0; i < size; i++) {
    printf("%s\n", *(arr + i));
  }
  printf("\n");
}
void swap(char **s, int index1, int index2) {
  char *t = s[index1];
  s[index1] = s[index2];
  s[index2] = t;
}
void reverse(char **s, int start, int end) {
  while (start < end) {
    swap(s, start++, end--);
  }
}
int next_permutation(int n, char **s) {
  int found_index = -1;
  for (int i = 0; i < n - 1; i++) {
    if (strcmp(s[i], s[i + 1]) < 0) {
      found_index = i;
    }
  }
  if (found_index >= 0) {
    int swap_index = 0;
    for (int j = found_index + 1; j < n; j++) {
      if (strcmp(s[found_index], s[j]) < 0) {
        swap_index = j;
      }
    }
    swap(s, found_index, swap_index);
    reverse(s, found_index + 1, n - 1);
  }
  return found_index >= 0 ? 1 : 0;
}

int main() {
  int n;
  // scanf("%d", &n);
  n = 3;
  char **s = (char **)malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++) {
    *(s + i) = (char *)malloc(11 * sizeof(char));
    // scanf("%s", *(arr + i));
    // *(arr + i) = (char *)realloc(*(arr + i), strlen(*(arr + i)) + 1);
  }
  s[0] = (char *)"a";
  s[1] = (char *)"bc";
  s[2] = (char *)"bc";
  // s[3] = (char *)"3";
  puts("==========OUTPUT===========");

  do {
    for (int i = 0; i < n; i++) {
      printf(" %s%c", s[i], i == n - 1 ? '\n' : ' ');
    }
  } while (next_permutation(n, s));
  // for (int i = 0; i < n; i++) {
  //   if (s[i]) free(s[i]);
  // }
  free(s);
  return 0;
}