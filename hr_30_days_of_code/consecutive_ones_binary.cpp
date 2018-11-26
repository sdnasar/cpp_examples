#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 5;
  // cin >> n;
  // cin.ignore(numeric_limits<streamsize>::max(), '\n');
  string binary = bitset<8>(n).to_string();
  cout << binary << endl;
  int result = 0;
  int temp = 0;
  bool previous = false;
  for (auto& s : binary) {
    cout << s << endl;
    if (s == '1') {
      previous = true;
      temp += 1;
      if (temp > result) {
        result = temp;
      }
    } else {
      previous = false;
      temp = 0;
    }
  }
  cout << result << endl;

  return 0;
}
