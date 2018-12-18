#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
input:
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0

output:
19
*/

int main() {
  vector<vector<int> > arr(6, vector<int>(6));
  for (int arr_i = 0; arr_i < 6; arr_i++) {
    for (int arr_j = 0; arr_j < 6; arr_j++) {
      cin >> arr[arr_i][arr_j];
    }
  }
  int sum = -9999;
  int temp = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      temp = temp + arr[i][j] + arr[i][j + 1] + arr[i][j + 2] +
             arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] +
             arr[i + 2][j + 2];
      if (sum < temp) sum = temp;
      temp = 0;
    }
  }
  cout << sum << endl;
  return 0;
}
