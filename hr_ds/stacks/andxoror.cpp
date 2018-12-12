#include <bits/stdc++.h>

using namespace std;
#define maxof(a, b) a > b ? a : b
vector<string> split_string(string);

/*
si =(((m1 and m2) xor ( m1 or m2)) and (m1 xor m2))

input :
5
9 6 3 5 2


output:
15

*/

int calculate(int a, int b) { return (((a & b) ^ (a | b)) & (a | b)); }

int andXorOr(vector<int> a) {
  int res = 0;
  stack<int> s;
  for (auto i : a) {
    while (!s.empty()) {
      res = max(res, calculate(i, s.top()));
      if (i < s.top())
        s.pop();
      else
        break;
    }
    s.push(i);
  }
  return res;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int a_count;
  cin >> a_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string a_temp_temp;
  getline(cin, a_temp_temp);

  vector<string> a_temp = split_string(a_temp_temp);

  vector<int> a(a_count);

  for (int a_itr = 0; a_itr < a_count; a_itr++) {
    int a_item = stoi(a_temp[a_itr]);

    a[a_itr] = a_item;
  }

  int result = andXorOr(a);
  cout << result << endl;
  fout << result << "\n";

  fout.close();

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char &x, const char &y) { return x == y and x == ' '; });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(
      input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
