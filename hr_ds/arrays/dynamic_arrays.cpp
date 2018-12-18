#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

/*
input:
2 5
1 0 5
1 1 7
1 0 3
2 1 0
2 1 1

output:
7
3
*/
int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n;
  cin >> n;
  int lastAns = 0;
  vector<int> seq[n];
  int q;
  cin >> q;
  int a, b, c, sno;
  for (int i = 0; i < q; i++) {
    cin >> a >> b >> c;
    sno = (b ^ lastAns) % n;
    if (a == 1) {
      seq[sno].push_back(c);
    } else {
      lastAns = seq[sno][c % seq[sno].size()];
      cout << lastAns << endl;
    }
  }
  return 0;
}
