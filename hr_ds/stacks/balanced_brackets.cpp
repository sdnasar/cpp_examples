#include <bits/stdc++.h>
/*

we say a sequence of brackets is balanced if the following conditions are met:

    It contains no unmatched brackets.
    The subset of brackets enclosed within the confines of a matched pair of
brackets is also a matched pair of brackets.

Given n strings of brackets, determine whether each sequence of brackets is
balanced. If a string is balanced, return YES. Otherwise, return NO.

input:
3
{[()]}
{[(])}
{{[[(())]]}}

output:
YES
NO
YES


input:
3
{(([])[])[]}
{(([])[])[]]}
{(([])[])[]}[]

output:
YES
NO
YES

input:
6
}][}}(}][))]
[](){()}
()
({}([][]))[]()
{)[](}]}]}))}(())(
([[)


output:
NO
YES
YES
YES
NO
NO

*/
using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
  if (s.empty() || s.length() % 2 != 0) return "NO";
  stack<char> stk;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
      stk.push(s[i]);
      continue;
    }
    if (stk.empty()) return "NO";
    char x = stk.top();
    stk.pop();
    switch (x) {
      case '{':
        if (s[i] != '}') return "NO";
        break;
      case '(':
        if (s[i] != ')') return "NO";
        break;
      case '[':
        if (s[i] != ']') return "NO";
        break;
    }
  }
  return stk.empty() ? "YES" : "NO";
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));
  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    string s;
    getline(cin, s);

    string result = isBalanced(s);
    cout << result << endl;
    fout << result << "\n";
  }

  fout.close();

  return 0;
}
