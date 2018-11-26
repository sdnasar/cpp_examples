/// lambda expressions along with pre defined algorithms
/// [] means capture clause which is used to capture variable from surrounding
/// scope capturing can be done in 3 ways - by reference(&), by value(=),
/// mix(&,=)
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isOdd(int i) { return (i % 2) == 1; }
int main() {
  vector<int> v;
  int comparator = 3;
  int j = 3;
  for (int i = 0; i < 10; i++) v.push_back(i);
  //    long count = count_if(v.begin(), v.end(), isOdd); // passing predicate
  //    long count = count_if(v.begin(), v.end(), [](int i){ return
  //    ((i%2)==1); }); // lambda function
  /// with reference capture
  long count =
      count_if(v.begin(), v.end(), [&](int i) { return (i % j) == 0; });
  cout << count << endl;
  return 0;
}
