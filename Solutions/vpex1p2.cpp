#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main () {

  int people;
  cin >> people;

  vector <int> slices;
  for (int i{0}; i<people; i++){
    int slice;
    cin >> slice;
    slices.push_back(slice);
  }

  int sum{0};
  for (auto n: slices){
    sum+=n;
  }
  int average = sum / people;

  int notReceived{0};
  for (auto n: slices){
    if(n!=average){
      notReceived++;
    }
  }

  cout << notReceived;

  return 0;
}
