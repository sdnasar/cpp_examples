#include <bits/stdc++.h>
using namespace std;
#define maxof(a, b) a > b ? a : b
vector<string> split_string(string);

/*
input:
1
5 4 10
4 2 4 6 1
2 1 8 5

output:
4

input:
1
20 35 67
19 9 8 13 1 7 18 0 19 19 10 5 15 19 0 0 16 12 5 10
11 17 1 18 14 12 9 18 14 3 4 13 4 12 6 5 12 16 5 11 16 8 16 3 7 8 3 3 0 1 13 4
10 7 14

output:
6

input:
1
4 50 94
11 16 9 15
2 4 0 3 3 14 18 4 5 1 16 11 11 0 6 11 12 7 14 6 11 19 14 4 12 15 9 15 11 18 10
14 15 2 9 10 16 7 15 13 8 3 4 12 4 11 3 16 18 18

output:
14
*/
int twoStacks(int x, vector<int> a, vector<int> b) {
  int sum = 0;
  int i = 0, j = 0;
  int count = 0;

  while (i < a.size()) {
    sum += a[i];
    i++;
    if (sum > x) {
      i--;
      sum -= a[i];
      break;
    }
  }
  count = i;

  while (j < b.size()) {
    sum += b[j];
    j++;
    while (sum > x && i > 0) {
      i--;
      sum -= a[i];
    }
    count = (sum <= x) ? maxof((count), (i + j)) : count;
  }

  return count;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int g;
  cin >> g;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  vector<int> res;
  for (int g_itr = 0; g_itr < g; g_itr++) {
    string nmx_temp;
    getline(cin, nmx_temp);

    vector<string> nmx = split_string(nmx_temp);

    int n = stoi(nmx[0]);

    int m = stoi(nmx[1]);

    int x = stoi(nmx[2]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int a_itr = 0; a_itr < n; a_itr++) {
      int a_item = stoi(a_temp[a_itr]);

      a[a_itr] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split_string(b_temp_temp);

    vector<int> b(m);

    for (int b_itr = 0; b_itr < m; b_itr++) {
      int b_item = stoi(b_temp[b_itr]);

      b[b_itr] = b_item;
    }

    int result = twoStacks(x, a, b);
    res.push_back(result);
    fout << result << "\n";
  }

  fout.close();
  cout << "================" << endl;
  for (auto &a : res) cout << a << endl;

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
