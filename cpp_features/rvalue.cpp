/// lvalue - An lvalue is an expression that refers to a memory location and
/// allows us to take the address of that memory location via the & operator
/// rvalue - An rvalue is an expression that is not an lvalue
#include <iostream>

using namespace std;

void f(int &&a) { cout << a << endl; }

int main() {
  int b = 9;
  f(b + 7);
  return 0;
}
