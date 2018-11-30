#include <bits/stdc++.h>
#define maxof(a, b) a > b ? a : b
/*
input:
7
6 5 8 4 7 10 9

output:
2

output:
16
*/

using namespace std;

vector<string> split_string(string);

// Complete the poisonousPlants function below.
int poisonousPlants(vector<int> p) {
  int res = 0;
  int len = p.size();
  stack<pair<int, int>> s;
  s.push(make_pair(p[len - 1], 0));

  for (int i = len - 2; i >= 0; i--) {
    int days = 0;
    while (!s.empty() && s.top().first > p[i]) {
      // days += 1;
      days = maxof(days + 1, s.top().second);
      s.pop();
    }
    res = maxof(days, res);
    s.push(make_pair(p[i], days));
  }

  cout << res << endl;
  return res;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string p_temp_temp;
  getline(cin, p_temp_temp);

  vector<string> p_temp = split_string(p_temp_temp);

  vector<int> p(n);

  for (int i = 0; i < n; i++) {
    cout << i << ":" << p_temp[i] << endl;
    int p_item = stoi(p_temp[i]);
    p[i] = p_item;
  }
  int result = poisonousPlants(p);

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
