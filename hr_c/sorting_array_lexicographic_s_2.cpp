#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline void swap(char **a, char **b) {
  char *tmp = *a;
  *a = *b;
  *b = tmp;
}

inline int count_distinct_chars(const char *s) {
  int count = 0;
  int temp[128] = {0};
  while (*s != '\0') {
    if (!temp[*s]) {
      temp[*s]++;
      ++count;
    }
    ++s;
  }
  return count;
}

inline void print_array(char **arr, const int size) {
  for (int i = 0; i < size; i++) {
    printf("%s\n", *(arr + i));
  }
  printf("\n");
}

// non -decreasing
int lexicographic_sort(char *a, char *b) { return strcmp(a, b); }

// non -increasing
int lexicographic_sort_reverse(char *a, char *b) { return strcmp(b, a); }

// non -decreasing
int sort_by_length(char *a, char *b) {
  int res = strlen(a) - strlen(b);
  return res == 0 ? lexicographic_sort(a, b) : res;
}
// non -decreasing
int sort_by_number_of_distinct_characters(char *a, char *b) {
  int res = count_distinct_chars(a) - count_distinct_chars(b);
  return res == 0 ? lexicographic_sort(a, b) : res;
}

void string_sort(char **arr, const int size, int (*cmp)(char *a, char *b)) {
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (cmp(*(arr + i), *(arr + j)) > 0) {
        // printf("Address of word: %p %p\n", &arr[i], &arr[j]);
        swap(&*(arr + i), &*(arr + j));
        // printf("Value : %s %s\n", *&arr[i], *&arr[j]);
        // swap_addresses(i, j, arr);
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
  // *(arr + 0) = (char *)"World";
  // *(arr + 1) = (char *)"Helloisabigplace";
  // // *(arr + 0) = (char *)realloc(*(arr + 0), strlen(*(arr + 0)) + 1);
  // // *(arr + 1) = (char *)realloc(*(arr + 1), strlen(*(arr + 1)) + 1);
  puts("==========OUTPUT===========");
  // print_array(arr, n);
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