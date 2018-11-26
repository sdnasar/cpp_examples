#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
/*
input:
5 3
1 2 100
2 5 100
3 4 100

output:
200
*/
int main() {
  long int N, K, p, q, sum, i, j, max = 0, x = 0;

  cin >> N >> K;
  long int *a = new long int[N + 1]();

  for (i = 0; i < K; i++) {
    cin >> p >> q >> sum;
    a[p] += sum;
    if ((q + 1) <= N) a[q + 1] -= sum;
  }

  for (i = 1; i <= N; i++) {
    x = x + a[i];
    if (max < x) max = x;
  }

  cout << max;
  return 0;
}