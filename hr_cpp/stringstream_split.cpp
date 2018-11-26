#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> parseInts(string str) {
  vector<int> v;
  stringstream ss(str);
  int a;
  char c;
  while (ss >> a) {
    v.push_back(a);
    ss >> c;
  }
  return v;
}

int main() {
  string str;
  cin >> str;
  vector<int> integers = parseInts(str);
  for (int i = 0; i < integers.size(); i++) {
    cout << integers[i] << "\n";
  }

  return 0;
}