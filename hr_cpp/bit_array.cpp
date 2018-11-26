#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

/*

a[0] = S (modulo 2^31)
for i = 1 to N-1
a[i] = a[i-1]*P+Q (modulo 2^31)


input: 3 1 1 1
output: 3

input: 10000000 658061970 695098531 1430548937
output:10000000
*/

int main() {
  unsigned int N, S, P, Q, mu, nu;

  const unsigned int m = 1 << 31;

  cin >> N >> S >> P >> Q;

  unsigned int* a = new unsigned int[N];

  a[0] = S % m;

  for (int i = 1; i < N; i++) {
    a[i] = (a[i - 1] * P + Q) % m;
  }

  // begin cycle detection (-> floyd's algorithm)

  for (int i = 0; i < N; i++) {
    if ((2 * i) + 1 > N - 1) {
      // no cycle found -> N distinct values, output N, clean up and terminate
      // execution
      cout << N << endl;
      delete[] a;
      return 0;

    } else if (a[i] == a[(2 * i) + 1]) {
      // cycle detected, break loop to proceed with algorithm
      nu = i + 1;
      break;
    }
  }

  // find first element of cycle

  for (int i = 0; i < N; i++) {
    if (a[i] == a[i + nu]) {
      mu = i;
      break;
    }
  }

  // find first reoccurence of first cycle element

  for (int i = mu + 1; i < N; i++) {
    if (a[mu] == a[i]) {
      // number of elements up until first repeated cycle element = number of
      // distinct values in sequence

      cout << i << endl;
      break;
    }
  }

  delete[] a;

  return 0;
}