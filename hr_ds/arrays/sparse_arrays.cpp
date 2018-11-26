#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
       int n;
    int q;
    int count=0;
    cin >> n;
    vector<string> arr;
    string temp;
    for (int i=0;i<n;i++)
        {
        temp.clear();
        cin>> temp;
        arr.push_back(temp);
    }
    cin >> q;
    for (int i=0;i<q;i++)
        {
        temp.clear();
        cin>> temp;
        for (int i=0;i<n;i++) {
            if (arr[i].compare(temp)==0)
                count++;
        }
        cout << count << endl;
        count=0;
    }
    
    return 0;
}
