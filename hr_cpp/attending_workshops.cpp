/*
Input:
6
1 3 0 5 5 8
1 1 6 2 4 1

Output:
4


Input 2:
5
1 2 3 4 5
1 1 1 1 1

Output:
5

Input 3:
2
72 52
3 9

Output:
2

Input 4:
8
5 5 6 3 4 1 3 2
1 2 5 1 1 1 2 1

Output:
6

*/
#include <bits/stdc++.h>

using namespace std;

typedef struct Workshop {
  int start_time;
  int duration;
  int end_time;
} Workshop;

typedef struct Available_Workshops {
  int n;
  vector<Workshop> workshops;
  Available_Workshops(int l) { n = l; }
} Available_Workshops;

Available_Workshops* initialize(int start_time[], int duration[], int n) {
  Available_Workshops* aw = new Available_Workshops(n);
  for (int i = 0; i < n; i++) {
    Workshop w;
    w.start_time = start_time[i];
    w.duration = duration[i];
    w.end_time = start_time[i] + duration[i];
    aw->workshops.push_back(w);
  }
  sort(aw->workshops.begin(), aw->workshops.end(),
       [](const Workshop& w1, const Workshop& w2) {
         return w1.end_time < w2.end_time;
       });

  return aw;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
  int previous_endtime = -1;
  int workshops_attendable = 0;
  for (int i = 0; i < ptr->n; i++) {
    if (ptr->workshops[i].start_time >= previous_endtime) {
      previous_endtime = ptr->workshops[i].end_time;
      workshops_attendable += 1;
    }
  }
  return workshops_attendable;
}

int main(int argc, char* argv[]) {
  int n;  // number of workshops
  cin >> n;
  // create arrays of unknown size n
  int* start_time = new int[n];
  int* duration = new int[n];

  for (int i = 0; i < n; i++) {
    cin >> start_time[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> duration[i];
  }

  Available_Workshops* ptr;
  ptr = initialize(start_time, duration, n);
  cout << CalculateMaxWorkshops(ptr) << endl;
  return 0;
}
