/// template specialization to write common code based on datatypes
#include <iostream>

using namespace std;

template <class T>
void fun(T a) {
  cout << "The main template fun(): " << a << endl;
}

template <>
void fun(int a) {
  cout << "Specialized Template for int type: " << a << endl;
}

template <class T>
class Test {
 public:
  Test() { cout << "Common Template object\n"; }
};

template <>
class Test<int> {
 public:
  Test() { cout << "Specialized Template for int type object\n"; }
};

int main() {
  fun<char>('a');
  fun<int>(10);
  fun<float>(10.14);
  Test<char> T1;
  Test<float> T2;
  Test<int> T3;

  return 0;
}
