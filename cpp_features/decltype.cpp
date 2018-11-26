/// decltype - Inspects the declared type of an entity or the type and value
/// category of an expression. returns a type of entity or expression
#include <iostream>

using namespace std;

int main() {
  int i = 6;
  decltype(i) j;
  j = i;
  cout << j << endl;
}
