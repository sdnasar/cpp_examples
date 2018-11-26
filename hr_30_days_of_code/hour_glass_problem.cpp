#include <bits/stdc++.h>

using namespace std;
#define maxof(a, b) a > b ? a : b

/*
0 -4 -6 0 -7 -6
-1 -2 -6 -8 -3 -1
-8 -4 -2 -8 -8 -6
-3 -1 -2 -5 -7 -4
-3 -5 -3 -6 -6 -6
-3 -6 0 -8 -6 -7


-19


-1 1 -1 0 0 0
0 -1 0 0 0 0
-1 -1 -1 0 0 0
0 -9 2 -4 -4 0
-7 0 0 -2 0 0
0 0 -1 -2 -4 0

0
*/

int main() {
  vector<vector<int>> arr(6);
  for (int i = 0; i < 6; i++) {
    arr[i].resize(6);

    for (int j = 0; j < 6; j++) {
      cin >> arr[i][j];
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  int max_sum = 0;
  int sum = 0;
  bool first = false;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] +
            arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
      if (!first) {
        max_sum = sum;
        first = true;
        continue;
      }
      max_sum = maxof(max_sum, sum);
    }
  }
  cout << max_sum << endl;

  return 0;
}
