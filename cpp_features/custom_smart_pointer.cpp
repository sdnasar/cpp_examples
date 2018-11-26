/// custom smart pointer with overloaded operators to use it as raw pointer
#include <iostream>

using namespace std;

template <class T>
class SmrtPointer {
 private:
  T *p;

 public:
  explicit SmrtPointer(T *a = NULL) { p = a; }

  ~SmrtPointer() {
    cout << "dtor:SmrtPointer\n";
    delete p;
  }

  T &operator*() { return *p; }

  T *operator->() { return p; }
};

int main() {
  SmrtPointer<int> a(new int());
  *a = 20;
  cout << *a << endl;
}
