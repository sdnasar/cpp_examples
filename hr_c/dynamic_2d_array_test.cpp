#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // this stores total number of books in each shelve
  int *total_number_of_books;
  /*
  this stores total number of pages in each book of each shelve
  rows - shelves, columns - books
  */
  int **total_number_of_pages;  // number of pages in each book on each shelve
  int total_number_of_shelves = 5;
  total_number_of_books = (int *)malloc(total_number_of_shelves * sizeof(int));
  total_number_of_pages =
      (int **)malloc(total_number_of_shelves * sizeof(int *));

  for (int i = 0; i < total_number_of_shelves; i++) {
    *(total_number_of_books + i) = 0;
    *(total_number_of_pages + i) = (int *)malloc(100 * sizeof(int));
  }

  *(*(total_number_of_pages + 0) + *(total_number_of_books + 0)) = 15;

  *(total_number_of_books + 0) += 1;
  *(total_number_of_books + 1) += 1;
  *(total_number_of_books + 0) += 1;
  *(total_number_of_books + 4) += 1;

  // for (int i = 0; i < total_number_of_shelves; i++) {
  //   *(total_number_of_pages + i) =
  //       (int *)malloc(*(total_number_of_books + i) * sizeof(int));
  // }
  // total_number_of_pages[0][*(total_number_of_books + 0) - 1] = 15;

  for (int i = 0; i < total_number_of_shelves; i++) {
    printf("Shelve:%d,Books:%d\n", i, *(total_number_of_books + i));
  }
  for (int i = 0; i < total_number_of_shelves; i++) {
    for (int j = 0; j < *(total_number_of_books + 0); j++)
      printf("Shelve:%d,Book:%d,Pages:%d\n", i, j,
             *(*(total_number_of_pages + i) + j));
  }

  if (total_number_of_books) free(total_number_of_books);
  if (total_number_of_pages) {
    for (int i = 0; i < total_number_of_shelves; i++) {
      free(*(total_number_of_pages + i));
    }
    free(total_number_of_pages);
  }

  return 0;
}
