#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
input:
8
1 abc
3 3
2 3
1 xy
3 2
4
4
3 1

output:
c
y
a
*/
int main() {
  int q;
  cin >> q;
  stack<string> s;
  string scin, tmp;
  int o, k;
  while (q--) {
    cin >> o;
    switch (o) {
      case 1:  // append to string
        cin >> scin;
        if (s.empty())
          s.push(scin);
        else {
          tmp = s.top();
          s.push(tmp.append(scin));
        }
        break;
      case 2:  // delete the given number of characters from last
        cin >> k;
        tmp = s.top();
        tmp = tmp.substr(0, tmp.length() - k);
        s.push(tmp);
        break;
      case 3:  // print the given positioned character
        cin >> k;
        tmp = s.top();
        cout << tmp[k - 1] << endl;
        break;
      case 4:  // undo the last changed
        if (!s.empty()) s.pop();
        break;
    }
  }
  return 0;
}
