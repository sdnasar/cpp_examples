#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>

/*

Example

       4
    2     3
  1   3  5  7

The binary tree above has the following traversals:

    InOrder: 1 2 3 4 5 6 7
    PostOrder: 1 3 2 5 7 6 4
    PreOrder: 4 2 1 3 6 5 7
    Level-Order: 4 2 6 1 3 5 7

Input:
6
3
5
4
7
2
1

output:
3 2 5 1 4 7

*/

using namespace std;
class Node {
 public:
  int data;
  Node *left, *right;
  Node(int d) {
    data = d;
    left = right = NULL;
  }
};
class Solution {
 public:
  Node* insert(Node* root, int data) {
    if (root == NULL) {
      return new Node(data);
    } else {
      Node* cur;
      if (data <= root->data) {
        cur = insert(root->left, data);
        root->left = cur;
      } else {
        cur = insert(root->right, data);
        root->right = cur;
      }
      return root;
    }
  }
  void levelOrder(Node* root) {
    queue<Node*> q;
    if (root) {
      q.push(root);
      while (!q.empty()) {
        Node* n = q.front();
        cout << n->data << " ";
        q.pop();
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
      }
      cout << endl;
    }
  }
};  // End of Solution
int main() {
  Solution myTree;
  Node* root = NULL;
  int T, data;
  cin >> T;
  while (T-- > 0) {
    cin >> data;
    root = myTree.insert(root, data);
  }
  myTree.levelOrder(root);
  return 0;
}