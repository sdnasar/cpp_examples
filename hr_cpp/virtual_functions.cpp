#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define STUDENT_SUBJECTS 6

class Person {
 public:
  string name;
  int age;

  Person() {
    name.clear();
    age = 0;
  }
  // if not pure then defination should be given
  virtual void getdata(){};
  virtual void putdata(){};
};
class Professor : public Person {
 public:
  static int uniqueId;
  int publications, curId;
  void getdata() {
    cin >> name >> age >> publications;
    curId = ++uniqueId;
  }
  void putdata() {
    cout << name << " " << age << " " << publications << " " << curId << endl;
  }
};
class Student : public Person {
 public:
  static int uniqueId;
  int marks[STUDENT_SUBJECTS];
  int curId;
  void getdata() {
    cin >> name >> age;
    for (int i = 0; i < STUDENT_SUBJECTS; i++) {
      cin >> marks[i];
    }
    curId = ++uniqueId;
  }
  void putdata() {
    int sum = 0;
    for (auto &m : marks) sum += m;
    cout << name << " " << age << " " << sum << " " << curId << endl;
  }
};

int Professor::uniqueId = 0;
int Student::uniqueId = 0;

int main() {
  int n, val;
  cin >> n;  // The number of objects that is going to be created.
  Person *per[n];

  for (int i = 0; i < n; i++) {
    cin >> val;
    if (val == 1) {
      // If val is 1 current object is of type Professor
      per[i] = new Professor;

    } else
      per[i] = new Student;  // Else the current object is of type Student

    per[i]->getdata();  // Get the data from the user.
  }

  for (int i = 0; i < n; i++)
    per[i]->putdata();  // Print the required output for each object.

  return 0;
}
