#include <bits/stdc++.h>

/*
input:
5 3
1 2 100
2 5 100
3 4 100

output:
200
*/
using namespace std;

vector<string> split_string(string);

void printArray(vector<vector<long>> array, int n) {
  for (int i = 0; i < array.size(); i++) {
    for (int j = 0; j < n; j++) {
      cout << array[i][j] << " ";
    }
    cout << endl;
  }
}
// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
  // vector<vector<long>> v;
  vector<long> data(n, 0);
  // v.push_back(data);
  int a, b, k;
  long result = 0;
  int j = 1;
  for (int i = 0; i < queries.size(); i++) {
    a = queries[i][0];
    b = queries[i][1];
    k = queries[i][2];
    for (int j = a - 1; j < b; j++) {
      data[j] += k;
      if (result < data[j]) result = data[j];
    }

    // v.push_back(data);
  }
  // printArray(v, n);
  cout << "Result:" << result << endl;
  return result;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nm_temp;
  getline(cin, nm_temp);

  vector<string> nm = split_string(nm_temp);

  int n = stoi(nm[0]);  // size of array

  int m = stoi(nm[1]);  // number of operations

  vector<vector<int>> queries(m);
  for (int i = 0; i < m; i++) {
    queries[i].resize(3);

    for (int j = 0; j < 3; j++) {
      cin >> queries[i][j];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  long result = arrayManipulation(n, queries);

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
