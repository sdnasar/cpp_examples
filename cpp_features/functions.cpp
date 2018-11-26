/// function wrapper which can store,copy and invoke any callable target
#include <functional>
#include <iostream>

using namespace std;

bool isOdd(int i) { return (i % 2) == 1; }
int main() {
  function<bool(int)> f = isOdd;
  cout << f(5) << endl;
}
