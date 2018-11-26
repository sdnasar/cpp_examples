#include <cstddef>
#include <iostream>
#define max(a, b) a > b ? a : b
/*
input:
7
3
5
2
1
4
6
7

output:
3
*/

using namespace std;

class Node {
 public:
  int data;
  Node* left;
  Node* right;
  Node(int d) {
    data = d;
    left = NULL;
    right = NULL;
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
  int getHeight(Node* root) {
    // get height of left side
    // get height of right side
    // return max(left,right)
    if (root == NULL) return -1;
    int leftSide = 1 + getHeight(root->left);
    int rightSide = 1 + getHeight(root->right);
    return max(leftSide, rightSide);
  }
};  // End of Solution

int main() {
  Solution myTree;
  Node* root = NULL;
  int t;
  int data;

  cin >> t;

  while (t-- > 0) {
    cin >> data;
    root = myTree.insert(root, data);
  }
  int height = myTree.getHeight(root);
  cout << height;

  return 0;
}
