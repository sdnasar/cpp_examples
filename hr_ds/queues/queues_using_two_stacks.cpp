#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
input:
10
1 42
2
1 14
3
1 28
3
1 60
1 78
2
2

output:
14
14
*/

void pushInToQueueStack(stack<int> &src, stack<int> &dest) {
  while (!src.empty()) {
    dest.push(src.top());
    src.pop();
  }
}

int main() {
  int q;
  cin >> q;
  stack<int> stack1;
  stack<int> queueStack;
  while (q--) {
    int i;
    cin >> i;
    switch (i) {
      // insert
      case 1: {
        int x;
        cin >> x;
        stack1.push(x);
      } break;
        // delete front of queue
      case 2:
        if (!queueStack.empty()) {
          queueStack.pop();
        } else {
          pushInToQueueStack(stack1, queueStack);
          if (!queueStack.empty()) {
            queueStack.pop();
          }
        }
        break;
        // print front of queue
      case 3:
        if (!queueStack.empty()) {
          cout << queueStack.top() << endl;
        } else {
          pushInToQueueStack(stack1, queueStack);
          if (!queueStack.empty()) {
            cout << queueStack.top() << endl;
          }
        }
        break;
    }
  }
  return 0;
}
