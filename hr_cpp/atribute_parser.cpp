#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;
// -------- input -------
// 4 3
// <tag1 value = "HelloWorld">
// <tag2 name = "Name1">
// </tag2>
// </tag1>
// tag1.tag2~name
// tag1~name
// tag1~value
// ------- output ------
// Name1
// Not Found!
// HelloWorld

void tokenize(const string &str, const char delim, vector<string> &out) {
  std::stringstream ss(str);
  string s;
  while (getline(ss, s, delim)) {
    out.push_back(s);
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  getchar();
  map<string, string> parsedMap;
  string key = "";
  for (int i = 0; i < n; i++) {
    string s;
    getline(cin, s);
    vector<string> vout;
    tokenize(s, ' ', vout);
    s.clear();
    s = vout.at(0);
    size_t vsize = vout.size();
    int taglen = s.length();
    if (s.substr(0, 2).compare("</") == 0) {
      size_t pos = key.find_last_of(".");
      if (pos == string::npos)
        key.clear();
      else
        key = key.substr(0, pos);
      continue;
    }
    if (key.empty() && vsize == 1)
      key = s.substr(1, taglen - 2);
    else if (key.empty())
      key = s.substr(1, taglen - 1);
    else
      key += string(".") + s.substr(1, taglen - 1);

    bool isValue = false;
    string attribute;

    for (int i = 1; i < vsize; i++) {
      string value = vout[i];
      if (value == "=") continue;
      if (!isValue) {
        isValue = true;
        attribute = key + string("~") + value;
      } else {
        isValue = false;
        int length = value.length();
        int lengthToConsider =
            value.substr(length - 1, 1) == ">" ? (length - 3) : (length - 2);
        parsedMap.insert(
            make_pair(attribute, value.substr(1, lengthToConsider)));
        attribute.clear();
      }
    }
  }
  map<string, string>::iterator it;
  for (int i = 0; i < q; i++) {
    key.clear();
    cin >> key;
    it = parsedMap.find(key);
    if (it != parsedMap.end())
      cout << it->second << endl;
    else
      cout << "Not Found!" << endl;
  }
  return 0;
}
