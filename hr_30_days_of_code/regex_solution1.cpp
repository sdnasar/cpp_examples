/*
input
6
riya riya@gmail.com
julia julia@julia.me
julia sjulia@gmail.com
julia julia@gmail.com
samantha samantha@gmail.com
tanya tanya@gmail.com

first name alphabatically
output:
julia
julia
riya
samantha
tanya




input:

30
riya riya@gmail.com
julia julia@julia.me
julia sjulia@gmail.com
julia julia@gmail.com
samantha samantha@gmail.com
tanya tanya@gmail.com
riya ariya@gmail.com
julia bjulia@julia.me
julia csjulia@gmail.com
julia djulia@gmail.com
samantha esamantha@gmail.com
tanya ftanya@gmail.com
riya riya@live.com
julia julia@live.com
julia sjulia@live.com
julia julia@live.com
samantha samantha@live.com
tanya tanya@live.com
riya ariya@live.com
julia bjulia@live.com
julia csjulia@live.com
julia djulia@live.com
samantha esamantha@live.com
tanya ftanya@live.com
riya gmail@riya.com
priya priya@gmail.com
preeti preeti@gmail.com
alice alice@alicegmail.com
alice alice@gmail.com
alice gmail.alice@gmail.com


output:
alice
alice
julia
julia
julia
julia
preeti
priya
riya
riya
samantha
samantha
tanya
tanya
*/
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int main() {
  int N;
  cin >> N;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  vector<string> fnames;
  for (int N_itr = 0; N_itr < N; N_itr++) {
    string firstNameEmailID_temp;
    getline(cin, firstNameEmailID_temp);

    vector<string> firstNameEmailID = split_string(firstNameEmailID_temp);

    string firstName = firstNameEmailID[0];

    string emailID = firstNameEmailID[1];
    if (emailID.find("@gmail.com") != string::npos) {
      fnames.push_back(firstName);
    }
  }
  for (int i = 0; i < fnames.size(); i++) {
    for (int j = i + 1; j < fnames.size(); j++) {
      if (fnames[i][0] > fnames[j][0]) {
        string n = fnames[i];
        fnames[i] = fnames[j];
        fnames[j] = n;
        continue;
      }
      if (fnames[i][0] == fnames[j][0]) {
        for (int k = 1; k < fnames[i].size(); k++) {
          if (fnames[i][k] > fnames[j][k]) {
            string n = fnames[i];
            fnames[i] = fnames[j];
            fnames[j] = n;
            break;
          }
          if (fnames[i][k] < fnames[j][k]) {
            break;
          }
        }
      }
    }
  }
  cout << "============" << endl;
  for (auto &name : fnames) cout << name << endl;

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char &x, const char &y) { return x == y and x == ' '; });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(
      input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
