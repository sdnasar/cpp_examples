/*
Remove duplicates from the lined list
input:
6
1
2
2
3
3
4

output:
1 2 3 4
*/
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
class Node {
 public:
  int data;
  Node *next;
  Node(int d) {
    data = d;
    next = NULL;
  }
};
class Solution {
 public:
  Node *removeDuplicates(Node *head) {
    if (head == NULL) return NULL;
    Node *a = head;
    Node *b = head;
    while (a) {
      while (b->next) {
        if (a->data == b->next->data) {
          Node *t = b->next;
          b->next = b->next->next;
          delete t;
        } else
          b = b->next;
      }
      a = a->next;
      b = a;
    }
    return head;
  }
  Node *insert(Node *head, int data) {
    Node *p = new Node(data);
    if (head == NULL) {
      head = p;

    } else if (head->next == NULL) {
      head->next = p;

    } else {
      Node *start = head;
      while (start->next != NULL) {
        start = start->next;
      }
      start->next = p;
    }
    return head;
  }
  void display(Node *head) {
    Node *start = head;
    while (start) {
      cout << start->data << " ";
      start = start->next;
    }
  }
};

int main() {
  Node *head = NULL;
  Solution mylist;
  int T, data;
  cin >> T;
  while (T-- > 0) {
    cin >> data;
    head = mylist.insert(head, data);
  }
  // head = mylist.insert(head, 1);
  // head = mylist.insert(head, 2);
  // head = mylist.insert(head, 3);
  // head = mylist.insert(head, 3);
  // head = mylist.insert(head, 4);
  head = mylist.removeDuplicates(head);

  mylist.display(head);
}