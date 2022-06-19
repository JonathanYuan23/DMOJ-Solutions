#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main () {

  vector <int> cases 
  = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000};

  int n; cin >> n;

  for(int i=0; i<n; i++)
  {
    int num;
    cin >> num;
    cases[num-1] = 0;
  }

  int offer;
  cin >> offer;

  int sum=0;
  for(auto n: cases)
    sum+=n;

  int average = sum/(cases.size()-n);

  if(average>offer)
    cout << "no deal" << endl;
  else
    cout << "deal" << endl;

  return 0;
}
