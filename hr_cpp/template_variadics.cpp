#include <iostream>

using namespace std;

// Enter your code for reversed_binary_value<bool...>()
// template <bool a>
// int reversed_binary_value() {
//   return a;
// }
// template <bool a, bool b, bool... d>
// int reversed_binary_value() {
//   return (reversed_binary_value<b, d...>() << 1) + a;
// }
template <bool... digits>
int reversed_binary_value() {
  bool bools[] = {digits...};
  int result = 0;
  for (int i = 0; i < sizeof(bools) / sizeof(bool); i++) {
    result += bools[i] * 1 << i;
  }
  return result;
}

template <int n, bool... digits>
struct CheckValues {
  static void check(int x, int y) {
    CheckValues<n - 1, 0, digits...>::check(x, y);
    CheckValues<n - 1, 1, digits...>::check(x, y);
  }
};

template <bool... digits>
struct CheckValues<0, digits...> {
  static void check(int x, int y) {
    int z = reversed_binary_value<digits...>();
    std::cout << (z + 64 * y == x);
  }
};

int main() {
  // int decimal_num = 1 * (1 << 2);
  // cout << decimal_num << endl;
  int t;

  // std::cin >> t;
  CheckValues<6>::check(65, 1);
  for (int i = 0; i != t; ++i) {
    int x, y;
    cin >> x >> y;
    CheckValues<6>::check(x, y);
    cout << "\n";
  }
}
