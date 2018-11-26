#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    int d;
    cin >> d;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int temp[n];
    int tempIndex=0;
    for (int i=d;i<n;i++)
        {
          temp[tempIndex]=arr[i];
          tempIndex++;
    }
    for(int i=0;i<d;i++){
        temp[tempIndex]=arr[i];
         tempIndex++;
    }  
    for(int i=0;i<n;i++)
        cout << temp[i] << " ";
     cout << endl;
    return 0;
}
