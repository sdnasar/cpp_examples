/// classes and operator overloading along with copy constructor.
#include <bits/stdc++.h>

using namespace std;

class Box {
 private:
  int _length, _breadth, _height;

 public:
  Box() : _length(0), _breadth(0), _height(0) {}
  Box(int l, int b, int h) : _length(l), _breadth(b), _height(h) {}
  Box(const Box& b) {
    _length = b._length;
    _breadth = b._breadth;
    _height = b._height;
  }
  int getLength() { return _length; }
  int getBreadth() { return _breadth; }
  int getHeight() { return _height; }
  long long CalculateVolume() {
    return (long long)_length * _breadth * _height;
  }
  bool operator<(Box& b) {
    if (_length < b._length) return true;
    if (_breadth < b._breadth && _length == b._length) return true;
    if (_height < b._height && _breadth == b._breadth && _length == b._length)
      return true;
    return false;
  }
  friend ostream& operator<<(ostream& out, Box& b) {
    out << b._length << " " << b._breadth << " " << b._height;
    return out;
  }
};

void check2() {
  int n;
  cin >> n;
  Box temp;
  for (int i = 0; i < n; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      cout << temp << endl;
    }
    if (type == 2) {
      int l, b, h;
      cin >> l >> b >> h;
      Box NewBox(l, b, h);
      temp = NewBox;
      cout << temp << endl;
    }
    if (type == 3) {
      int l, b, h;
      cin >> l >> b >> h;
      Box NewBox(l, b, h);
      if (NewBox < temp) {
        cout << "Lesser\n";
      } else {
        cout << "Greater\n";
      }
    }
    if (type == 4) {
      cout << temp.CalculateVolume() << endl;
    }
    if (type == 5) {
      Box NewBox(temp);
      cout << NewBox << endl;
    }
  }
}

int main() { check2(); }