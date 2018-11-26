// Operator Overloading
/*
Input Format

The overloaded operator + should receive two complex numbers (
and

) as parameters. It must return a single complex number.

The overloaded operator << should add "
" to the stream where is the real part and

is the imaginary part of the complex number which is then passed as a parameter
to the overloaded operator.

Sample Input

3+i4
5+i6

Sample Output

8+i10

*/
#include <iostream>

using namespace std;

class Complex {
 public:
  int a, b;
  void input(string s) {
    int v1 = 0;
    int i = 0;
    while (s[i] != '+') {
      v1 = v1 * 10 + s[i] - '0';
      i++;
    }
    while (s[i] == ' ' || s[i] == '+' || s[i] == 'i') {
      i++;
    }
    int v2 = 0;
    while (i < s.length()) {
      v2 = v2 * 10 + s[i] - '0';
      i++;
    }
    a = v1;
    b = v2;
  }
};
// Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"
Complex operator+(const Complex& a, const Complex& b) {
  return {a.a + b.a, a.b + b.b};
}

ostream& operator<<(ostream& out, const Complex& c) {
  return out << c.a << (c.b > 0 ? '+' : '-') << 'i' << c.b;
}
int main() {
  Complex x, y;
  string s1, s2;
  cin >> s1;
  cin >> s2;
  x.input(s1);
  y.input(s2);
  Complex z = x + y;
  cout << z << endl;
}
