#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

/*
Time consuming solution

a[0] = S (modulo 2^31)
for i = 1 to N-1
a[i] = a[i-1]*P+Q (modulo 2^31)


input: 3 1 1 1
output: 3
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

  set<unsigned int> s;
  for (int i = 0; i < N; i++) s.insert(a[i]);
  cout << s.size() << endl;

  delete[] a;

  return 0;
}