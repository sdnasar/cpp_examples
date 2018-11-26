#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct triangle {
  int a;
  int b;
  int c;
};

typedef struct triangle triangle;

void sort_by_area(triangle *tr, int n) {
  double *areas = (double *)malloc(n * sizeof(double));
  for (int i = 0; i < n; i++) {
    double p = (tr[i].a + tr[i].b + tr[i].c) / 2;
    double r = p * (p - tr[i].a) * (p - tr[i].b) * (p - tr[i].c);
    double s = sqrt(r);
    areas[i] = sqrt(r);
    printf("Area of :%d is %f\n", i, areas[i]);
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (areas[i] > areas[j]) {
        triangle t = tr[j];
        tr[j] = tr[i];
        tr[i] = t;
      }
    }
  }
}
int main() {
  int n = 3;
  // scanf("%d", &n);
  triangle *tr = (triangle *)malloc(n * sizeof(triangle));
  // for (int i = 0; i < n; i++) {
  // 	scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
  // }
  tr[0].a = 7;
  tr[0].b = 24;
  tr[0].c = 25;
  tr[1].a = 5;
  tr[1].b = 12;
  tr[1].c = 13;
  tr[2].a = 3;
  tr[2].b = 4;
  tr[2].c = 5;

  sort_by_area(tr, n);
  for (int i = 0; i < n; i++) {
    printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
  }
  return 0;
}