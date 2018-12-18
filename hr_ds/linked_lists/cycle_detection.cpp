#include <bits/stdc++.h>
/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the
list is empty.

A Node is defined as:
   
*/
struct Node {
  int data;
  struct Node *next;
};

bool has_cycle(Node *head) {
  if (head == NULL) return false;
  Node *n1 = head;
  Node *n2 = head->next;
  while (n1 != NULL && n2 != NULL && n2->next != NULL) {
    if (n1 == n2) return true;
    n1 = n1->next;
    n2 = n2->next->next;
  }
  return false;
}

int main() {}
