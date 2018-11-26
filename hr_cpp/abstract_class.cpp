#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

/*
Given an abstract base class Cache with member variables and functions:

mp - Map the key to the node in the linked list
cp - Capacity
tail - Double linked list tail pointer
head - Double linked list head pointer
set() - Set/insert the value of the key, if present, otherwise add the key as
the most recently used key. If the cache has reached its capacity, it should
replace the least recently used key with a new key. get() - Get the value (will
always be positive) of the key if the key exists in the cache, otherwise return
-1.

You have to write a class LRUCache which extends the class Cache and uses the
member functions and variables to implement an LRU cache.

Input Format

First line of input will contain the N number of lines containing get or set
commands followed by the capacity of the cache. The following lines can either
contain get or set commands. An input line starting with get will be followed by
a key to be found in the cache. An input line starting with set will be followed
by the key and value respectively to be inserted/replaced in the cache.

Sample Input

3 1
set 1 2
get 1
get 2

Sample Output

2
-1

Explanation

Since, the capacity of the cache is 1, the first set results in setting up the
key 1 with it's value 2. The first get results in a cache hit of key 1, so 2 is
printed as the value for the first get. The second get is a cache miss, so -1 is
printed.

*/

struct Node {
  Node *next;
  Node *prev;
  int value;
  int key;

  Node(Node *p, Node *n, int k, int val)
      : prev(p), next(n), key(k), value(val){};

  Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache {
 protected:
  map<int, Node *> mp;             // map the key to the node in the linked list
  int cp;                          // capacity
  Node *tail;                      // double linked list tail pointer
  Node *head;                      // double linked list head pointer
  virtual void set(int, int) = 0;  // set function
  virtual int get(int) = 0;        // get function
};

class LRUCache : public Cache {
 private:
  map<int, Node *>::iterator cache;

 public:
  LRUCache(int capacity) {
    cp = capacity;
    tail = nullptr;
    head = nullptr;
  }

  ~LRUCache() {
    for (auto &a : mp) {
      if (a.second) delete a.second;
    }
  }

  void set(int key, int value) {
    if (mp.size() + 1 > cp) {
      tail = tail->prev;
      mp.erase(tail->next->key);
      delete tail->next;
      tail->next = nullptr;
    }

    cache = mp.find(key);
    if (cache != mp.end()) {
      cache->second->value = value;
      if (cache->second == head) {
        return;
      }
      cache->second->prev->next = cache->second->next;
      if (cache->second == tail) {
        tail = tail->prev;
      } else {
        cache->second->next->prev = cache->second->prev;
      }
      head->prev = cache->second;
      cache->second->next = head;
      cache->second->prev = nullptr;
      head = cache->second;

      return;
    }

    Node *n;
    if (head == NULL) {
      n = new Node(key, value);
      head = n;
      tail = n;
    } else {
      n = new Node(head->prev, head, key, value);
      head->prev = n;
      head = n;
    }
    mp[key] = n;
  }

  int get(int key) {
    cache = mp.find(key);
    if (cache == mp.end()) return -1;
    return cache->second->value;
  }
};

int main() {
  int n, capacity, i;
  cin >> n >> capacity;
  LRUCache l(capacity);
  vector<int> vout;
  for (i = 0; i < n; i++) {
    string command;
    cin >> command;
    if (command == "get") {
      int key;
      cin >> key;
      int r = l.get(key);
      vout.push_back(r);  // testing
      cout << r << endl;
    } else if (command == "set") {
      int key, value;
      cin >> key >> value;
      l.set(key, value);
    }
  }
  cout << "========TESTING=====" << endl;
  ofstream myfile;
  myfile.open("out.txt");
  for (auto &a : vout) {
    myfile << a << endl;
  }
  myfile.close();
  return 0;
}
