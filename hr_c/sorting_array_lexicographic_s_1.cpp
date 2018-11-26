#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline void swap(char **a, char **b) {
  char *tmp = (char *)malloc(strlen(*a));
  strcpy(tmp, *a);
  *a = (char *)realloc(*b, strlen(*b));
  *b = (char *)realloc(tmp, strlen(tmp));
}

inline void print_array(char **arr, const int size) {
  for (int i = 0; i < size; i++) {
    printf("%s\n", *(arr + i));
  }
  printf("\n");
}

// non -decreasing
int lexicographic_sort(char *a, char *b) {
  size_t alen = strlen(a);
  size_t blen = strlen(b);
  int loop = alen;
  if (alen > blen) {
    loop = blen;
  }
  for (int i = 0; i < loop; i++) {
    int v = *(a + i) - *(b + i);
    if (v != 0) return v;
    if (blen == 1) return 1;
  }

  return 0;
}

// non -increasing
int lexicographic_sort_reverse(char *a, char *b) {
  size_t alen = strlen(a);
  size_t blen = strlen(b);
  int loop = alen;
  if (alen > blen) {
    loop = blen;
  }
  for (int i = 0; i < loop; i++) {
    int v = *(b + i) - *(a + i);
    if (v != 0) return v;
    if (blen > 1) return 1;
  }

  return 0;
}

// non -decreasing
int sort_by_length(char *a, char *b) {
  int len_a = strlen(a);
  int len_b = strlen(b);
  if (len_a > len_b) {
    return 1;
  }
  if (len_a == len_b) {
    return lexicographic_sort(a, b);
  }
  return 0;
}
// non -decreasing
int sort_by_number_of_distinct_characters(char *a, char *b) {
  char *tmpa = (char *)malloc(strlen(a));
  memset(tmpa, 0x00, strlen(tmpa));
  *(tmpa + 0) = *(a + 0);
  size_t tmpa_len = 1;
  bool found = false;
  for (int i = 1; i < strlen(a); i++) {
    char c = *(a + i);
    for (int j = 0; j < tmpa_len; j++) {
      if (*(tmpa + j) == c) {
        found = true;
        break;
      }
    }
    if (!found) {
      *(tmpa + tmpa_len) = c;
      ++tmpa_len;
    }
    found = false;
  }

  char *tmpb = (char *)malloc(strlen(b));
  memset(tmpb, 0x00, strlen(tmpb));
  *(tmpb + 0) = *(b + 0);
  size_t tmpb_len = 1;
  found = false;
  for (int i = 1; i < strlen(b); i++) {
    char c = *(b + i);

    for (int j = 0; j < tmpb_len; j++) {
      if (*(tmpb + j) == c) {
        found = true;
        break;
      }
    }
    if (!found) {
      *(tmpb + tmpb_len) = c;
      ++tmpb_len;
    }
    found = false;
  }

  int result = 0;
  if (tmpa_len > tmpb_len) {
    result = 1;
  } else if (tmpa_len == tmpb_len) {
    result = lexicographic_sort(a, b);
  }
  if (tmpa) free(tmpa);
  if (tmpb) free(tmpb);
  return result;
}

void string_sort(char **arr, const int size, int (*cmp)(char *a, char *b)) {
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (cmp(*(arr + i), *(arr + j)) > 0) {
        swap(&*(arr + i), &*(arr + j));
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  char **arr = (char **)malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++) {
    *(arr + i) = (char *)malloc(1024 * sizeof(char));
    scanf("%s", *(arr + i));
    *(arr + i) = (char *)realloc(*(arr + i), strlen(*(arr + i)) + 1);
  }

  print_array(arr, n);
  string_sort(arr, n, &lexicographic_sort);
  print_array(arr, n);
  string_sort(arr, n, &lexicographic_sort_reverse);
  print_array(arr, n);
  string_sort(arr, n, &sort_by_length);
  print_array(arr, n);
  string_sort(arr, n, &sort_by_number_of_distinct_characters);
  print_array(arr, n);

  printf("\n");
  return 0;
}