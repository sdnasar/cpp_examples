#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#define max(a, b) a > b ? a : b
using namespace std;

int main() {
  stack<int> s, t;
  int n;
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    switch (a) {
      case 1:
        int b;
        cin >> b;
        s.push(b);
        if (s.size() == 1)
          t.push(b);
        else
          t.push(max(b, t.top()));
        break;
      case 2:
        if (!s.empty()) {
          s.pop();
          t.pop();
        }
        break;
      case 3:
        cout << t.top() << endl;
        break;
    }
  }
  return 0;
}
